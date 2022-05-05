$NetBSD: patch-include.mk,v 1.1 2022/05/05 13:09:30 nia Exp $

Don't force -Werror.

--- include.mk.orig	2018-06-30 13:20:53.000000000 +0000
+++ include.mk
@@ -3,7 +3,7 @@ am__v_ERLC_ = $(am__v_ERLC_$(AM_DEFAULT_
 am__v_ERLC_0 = @echo "  ERLC    " $@;
 am__v_ERLC_1 =
 
-ERLC_GENERIC_FLAGS = -Werror  +debug_info $(DEBUG_ERLC_FLAGS)				\
+ERLC_GENERIC_FLAGS = +debug_info $(DEBUG_ERLC_FLAGS)				\
 		     -pa $(top_srcdir) -pa $(top_builddir) -pa $(top_builddir)/ebin	\
 		     -I $(top_srcdir)/include -I $(srcdir)/../include 			\
 		     -I $(top_builddir)/include -I $(builddir)/../include
