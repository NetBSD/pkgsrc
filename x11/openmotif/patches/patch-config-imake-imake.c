$NetBSD: patch-config-imake-imake.c,v 1.1.1.1 2000/10/29 16:17:13 mjl Exp $

--- config/imake/imake.c.orig	Sun Oct 29 15:34:13 2000
+++ config/imake/imake.c	Sun Oct 29 15:38:27 2000
@@ -148,6 +148,7 @@
 #if defined(__FreeBSD__) || defined(__NetBSD__)
 /* This needs to be before _POSIX_SOURCE gets defined */
 # include <sys/param.h>
+# include <sys/time.h>
 # include <sys/types.h>
 # include <sys/sysctl.h>
 #endif
