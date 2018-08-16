one_sideddir = $(pkglibexecdir)/mpi/one-sided
one_sided_PROGRAMS = osu_acc_latency osu_get_bw osu_get_latency osu_put_bibw osu_put_mbw osu_get_mbw osu_put_bw osu_put_latency

if MPI3_LIBRARY
    one_sided_PROGRAMS += osu_get_acc_latency osu_fop_latency osu_cas_latency
endif

osu_put_latency_SOURCES = osu_put_latency.c osu_1sc.c osu_mcdram.c osu_mcdram.h osu_1sc.h
osu_put_latency_LDFLAGS = -lhwloc
osu_put_mbw_SOURCES = osu_put_mbw.c osu_1sc.c osu_mcdram.c osu_mcdram.h osu_1sc.h
osu_put_mbw_LDFLAGS = -lhwloc
osu_get_mbw_SOURCES = osu_get_mbw.c osu_1sc.c osu_mcdram.c osu_mcdram.h osu_1sc.h
osu_get_mbw_LDFLAGS = -lhwloc
osu_put_bw_SOURCES = osu_put_bw.c osu_1sc.c osu_mcdram.c osu_mcdram.h osu_1sc.h
osu_put_bw_LDFLAGS = -lhwloc
osu_put_bibw_SOURCES = osu_put_bibw.c osu_1sc.c osu_mcdram.c osu_mcdram.h osu_1sc.h
osu_put_bibw_LDFLAGS = -lhwloc
osu_get_latency_SOURCES = osu_get_latency.c osu_1sc.c osu_mcdram.c osu_mcdram.h osu_1sc.h
osu_get_latency_LDFLAGS = -lhwloc
osu_get_bw_SOURCES = osu_get_bw.c osu_1sc.c osu_mcdram.c osu_mcdram.h osu_1sc.h
osu_get_bw_LDFLAGS = -lhwloc
osu_acc_latency_SOURCES = osu_acc_latency.c osu_1sc.c osu_mcdram.c osu_mcdram.h osu_1sc.h
osu_acc_latency_LDFLAGS = -lhwloc
osu_fop_latency_SOURCES = osu_fop_latency.c osu_1sc.c osu_mcdram.c osu_mcdram.h osu_1sc.h
osu_fop_latency_LDFLAGS = -lhwloc
osu_cas_latency_SOURCES = osu_cas_latency.c osu_1sc.c osu_mcdram.c osu_mcdram.h osu_1sc.h
osu_cas_latency_LDFLAGS = -lhwloc

if EMBEDDED_BUILD
    AM_LDFLAGS =
    AM_CPPFLAGS = -I$(top_builddir)/../src/include \
		  -I${top_srcdir}/../src/include
if BUILD_PROFILING_LIB
    AM_LDFLAGS += $(top_builddir)/../lib/lib@PMPILIBNAME@.la
endif
    AM_LDFLAGS += $(top_builddir)/../lib/lib@MPILIBNAME@.la
endif

if OPENACC
    AM_CFLAGS = -acc
endif
