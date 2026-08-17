$NetBSD: patch-src_main.c,v 1.1 2026/08/17 16:37:58 ryoon Exp $

* Fix build with GCC 14.

--- src/main.c.orig	2026-08-17 16:27:07.223472781 +0000
+++ src/main.c
@@ -28,6 +28,7 @@
 #include "dock.h"
 #include "preview_update.h"
 #include "gettext.h"
+#include "moveresize.h"
 
 #include <gdk/gdkx.h>
 #define SN_API_NOT_YET_FROZEN
