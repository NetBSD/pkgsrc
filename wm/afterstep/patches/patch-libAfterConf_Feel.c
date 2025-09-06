$NetBSD: patch-libAfterConf_Feel.c,v 1.1 2025/09/06 13:29:18 gutteridge Exp $

Need function prototype for XkbKeycodeToKeysym(3).

--- libAfterConf/Feel.c.orig	2013-05-01 13:34:11.000000000 +0000
+++ libAfterConf/Feel.c
@@ -20,6 +20,8 @@
 
 #define LOCAL_DEBUG
 
+#include <X11/XKBlib.h>
+
 #include "../configure.h"
 #include "../libAfterStep/asapp.h"
 #include "../libAfterStep/afterstep.h"
