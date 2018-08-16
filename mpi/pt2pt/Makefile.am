pt2ptdir = $(pkglibexecdir)/mpi/pt2pt
pt2pt_PROGRAMS = osu_bibw osu_bw osu_latency osu_mbw_mr osu_multi_lat

osu_bw_SOURCES = osu_bw.c osu_pt2pt.c osu_mcdram.c osu_mcdram.h osu_pt2pt.h 
osu_bw_LDFLAGS = -lhwloc
osu_bibw_SOURCES = osu_bibw.c osu_pt2pt.c osu_mcdram.c osu_mcdram.h osu_pt2pt.h
osu_bibw_LDFLAGS = -lhwloc
osu_latency_SOURCES = osu_latency.c osu_pt2pt.c osu_mcdram.c osu_mcdram.h osu_pt2pt.h
osu_latency_LDFLAGS = -lhwloc
osu_multi_lat_SOURCES = osu_multi_lat.c osu_pt2pt.c osu_mcdram.c osu_mcdram.h osu_pt2pt.h
osu_multi_lat_LDFLAGS = -lhwloc
osu_latency_mt_SOURCES = osu_latency_mt.c osu_pt2pt.c osu_mcdram.c osu_mcdram.h osu_pt2pt.h
osu_latency_mt_LDFLAGS = -lhwloc
osu_mbw_mr_SOURCES = osu_mbw_mr.c osu_mcdram.c osu_mcdram.h
osu_mbw_mr_LDFLAGS = -lhwloc

if MPI2_LIBRARY
    pt2pt_PROGRAMS += osu_latency_mt 
endif

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

