$NetBSD: patch-actions.c,v 1.2 2024/10/31 10:50:55 pin Exp $

Define `TIOCNOTTY' ioctl on SunOS using TTCOMPAT(4M).

--- actions.c.orig	2024-10-31 10:28:41.500126111 +0000
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
