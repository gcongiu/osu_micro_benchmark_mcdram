#ifndef OSU_MCDRAM_H_INCLUDED
#define OSU_MCDRAM_H_INCLUDED
void init_mcdram();
void fini_mcdram();
int alloc_mcdram_mem(void **buf, size_t size);
void free_mcdram_mem(void *buf, size_t size);
#endif /* OSU_MCDRAM_H_INCLUDED */

