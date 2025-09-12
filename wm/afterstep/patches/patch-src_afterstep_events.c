$NetBSD: patch-src_afterstep_events.c,v 1.1 2025/09/12 02:18:42 gutteridge Exp $

Need function prototype for XkbKeycodeToKeysym(3).

--- src/afterstep/events.c.orig	2013-05-01 13:34:11.000000000 +0000
+++ src/afterstep/events.c
@@ -45,6 +45,7 @@
 #include "../../libAfterStep/wmprops.h"
 #include "../../libAfterStep/moveresize.h"
 
+#include <X11/XKBlib.h>
 #include <X11/keysym.h>
 #ifdef XSHMIMAGE
 # include <sys/ipc.h>
