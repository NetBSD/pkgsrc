$NetBSD: patch-src_3rdparty_chromium_third__party_libXNVCtrl_NVCtrl.c,v 1.1 2021/08/03 21:04:36 markd Exp $

--- src/3rdparty/chromium/third_party/libXNVCtrl/NVCtrl.c.orig	2020-07-15 18:56:31.000000000 +0000
+++ src/3rdparty/chromium/third_party/libXNVCtrl/NVCtrl.c
@@ -27,10 +27,6 @@
  * libXNVCtrl library properly protects the Display connection.
  */
 
-#if !defined(XTHREADS)
-#define XTHREADS
-#endif /* XTHREADS */
-
 #define NEED_EVENTS
 #define NEED_REPLIES
 #include <stdint.h>
@@ -39,6 +35,11 @@
 #include <X11/Xutil.h>
 #include <X11/extensions/Xext.h>
 #include <X11/extensions/extutil.h>
+
+#if !defined(XTHREADS)
+#define XTHREADS
+#endif /* XTHREADS */
+
 #include "NVCtrlLib.h"
 #include "nv_control.h"
 
