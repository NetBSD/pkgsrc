$NetBSD: patch-actions.c,v 1.1 2024/03/10 21:02:21 vins Exp $

Define `TIOCNOTTY' ioctl on SunOS using TTCOMPAT(4M).

--- actions.c.orig	2024-03-10 19:16:37.092649863 +0000
+++ actions.c
@@ -28,6 +28,10 @@
 #include <limits.h>
 #include <X11/Xproto.h>
 #include <X11/extensions/XTest.h>
+#if defined(__sun)
+# define BSD_COMP
+# include <sys/stropts.h>
+#endif
 #include <sys/ioctl.h>
 
 #include "sdorfehs.h"
