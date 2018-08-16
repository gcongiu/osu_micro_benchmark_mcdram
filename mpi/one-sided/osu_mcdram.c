#include <hwloc.h>
#include <sys/mman.h>
#include <assert.h>
#include "osu_mcdram.h"

static int initialized = 0;
static hwloc_topology_t topology;
static hwloc_nodeset_t mcdram_nodes;

void init_mcdram() {
    int i;
    int numa_nodes;
    hwloc_obj_t obj;

    hwloc_topology_init(&topology);
    hwloc_topology_load(topology);

    numa_nodes = hwloc_get_nbobjs_by_type(topology, HWLOC_OBJ_NUMANODE);
    mcdram_nodes = hwloc_bitmap_alloc();

    for (i = 0; i < numa_nodes; i++) {
        obj = hwloc_get_obj_by_type(topology, HWLOC_OBJ_NUMANODE, i);
        if (obj->subtype && !strcmp(obj->subtype, "MCDRAM")) {
            hwloc_bitmap_or(mcdram_nodes, obj->nodeset, mcdram_nodes);
        }
    }

    initialized = 1;
}

void fini_mcdram() {
    hwloc_bitmap_free(mcdram_nodes);
    hwloc_topology_destroy(topology);
    initialized = 0;
}

int alloc_mcdram_mem(void **buf, size_t size) {
    char *bind_policy = NULL;
    char *bind_rule = NULL;
    char *bind_proc = NULL;
    hwloc_membind_policy_t membind_policy;
    int membind_flags = HWLOC_MEMBIND_BYNODESET;

    assert(initialized);

    bind_policy = getenv("OSU_MEMBIND_POLICY");
    bind_rule = getenv("OSU_MEMBIND_RULE");
    bind_proc = getenv("OSU_MEMBIND_PROC");

    if (bind_policy && strcmp(bind_policy, "BIND") == 0) {
        membind_policy = HWLOC_MEMBIND_BIND;
    } else if (bind_policy && strcmp(bind_policy, "FIRSTTOUCH") == 0) {
        membind_policy = HWLOC_MEMBIND_FIRSTTOUCH;
    } else if (bind_policy && strcmp(bind_policy, "INTERLEAVE") == 0) {
        membind_policy = HWLOC_MEMBIND_INTERLEAVE;
    } else if (bind_policy && strcmp(bind_policy, "NEXTTOUCH") == 0) {
        membind_policy = HWLOC_MEMBIND_NEXTTOUCH;
    } else if (bind_policy && strcmp(bind_policy, "MIXED") == 0) {
        membind_policy = HWLOC_MEMBIND_MIXED;
    } else {
        membind_policy = HWLOC_MEMBIND_DEFAULT;
    }

    if (bind_rule && strcmp(bind_rule, "STRICT") == 0) {
        membind_flags |= HWLOC_MEMBIND_STRICT;
    }

    if (bind_proc && strcmp(bind_proc, "PROCESS") == 0) {
        membind_flags |= HWLOC_MEMBIND_PROCESS;
    } else if (bind_proc && strcmp(bind_proc, "THREAD") == 0) {
        membind_flags |= HWLOC_MEMBIND_THREAD;
    } else if (bind_proc && strcmp(bind_proc, "MIGRATE") == 0) {
        membind_flags |= HWLOC_MEMBIND_MIGRATE;
    } else {
        membind_flags |= HWLOC_MEMBIND_NOCPUBIND;
    }

    *buf = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
    return hwloc_set_area_membind(topology, *buf, size, mcdram_nodes, membind_policy, membind_flags);
}

void free_mcdram_mem(void *buf, size_t size) {
    assert(initialized);
    munmap(buf, size);
}
