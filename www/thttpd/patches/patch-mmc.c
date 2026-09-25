$NetBSD: patch-mmc.c,v 1.1 2026/09/25 14:20:40 wiz Exp $

Turn off mmap on NetBSD up to 1.5L (__NetBSD_Version__ 105120000) and
include <sys/param.h> so that version is defined.

Before UBC arrived in 1.5L, mmap and read were not kept in sync, so
thttpd went on serving the old contents of a page after it had been
edited until it was restarted.  From PR pkg/25487, where Hauke Fath
reported it on 1.5.4 and Michael Santos wrote this hunk.

--- mmc.c.orig	2015-11-05 18:13:49.000000000 +0000
+++ mmc.c
@@ -37,6 +37,14 @@
 #include <fcntl.h>
 #include <syslog.h>
 #include <errno.h>
+
+#if defined(__NetBSD__)
+#include <sys/param.h>
+#endif
+
+#if (defined(__NetBSD__) && __NetBSD_Version__ <= 105120000)
+#undef HAVE_MMAP
+#endif
 
 #ifdef HAVE_MMAP
 #include <sys/mman.h>
