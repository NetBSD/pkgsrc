$NetBSD: patch-qtmultimedia.pro,v 1.1 2015/10/26 19:04:00 adam Exp $

Try to configure audio modules, despite QT_CONFIG set in qt5-qtbase.

--- qtmultimedia.pro.orig	2015-10-26 17:52:59.000000000 +0000
+++ qtmultimedia.pro
@@ -15,16 +15,10 @@ win32 {
 } else:qnx {
     qtCompileTest(mmrenderer)
 } else:!android {
-    contains(QT_CONFIG, alsa):qtCompileTest(alsa)
-    contains(QT_CONFIG, pulseaudio):qtCompileTest(pulseaudio)
+    qtCompileTest(alsa)
+    qtCompileTest(pulseaudio)
 
-    isEmpty(GST_VERSION) {
-        contains(QT_CONFIG, gstreamer-0.10) {
-            GST_VERSION = 0.10
-        } else: contains(QT_CONFIG, gstreamer-1.0) {
-            GST_VERSION = 1.0
-        }
-    }
+    GST_VERSION = 1.0
     cache(GST_VERSION, set)
     !isEmpty(GST_VERSION):qtCompileTest(gstreamer) {
         qtCompileTest(gstreamer_photography)
