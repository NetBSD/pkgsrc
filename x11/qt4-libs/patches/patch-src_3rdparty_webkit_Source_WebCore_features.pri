$NetBSD: patch-src_3rdparty_webkit_Source_WebCore_features.pri,v 1.1 2012/01/12 22:59:58 adam Exp $

Mac OS X: Problem linking with QTKit enabled.

--- src/3rdparty/webkit/Source/WebCore/features.pri.orig	2012-01-08 11:13:53.000000000 +0000
+++ src/3rdparty/webkit/Source/WebCore/features.pri
@@ -165,8 +165,8 @@ symbian|maemo5|maemo6 {
     mac:!contains(DEFINES, USE_QTMULTIMEDIA=1) {
         DEFINES -= ENABLE_VIDEO=0
         DEFINES += ENABLE_VIDEO=1
-        DEFINES += WTF_USE_QTKIT=1
-        DEFINES -= WTF_USE_QTKIT=0
+        DEFINES -= WTF_USE_QTKIT=1
+        DEFINES += WTF_USE_QTKIT=0
     } else: linux-*:!contains(DEFINES, USE_QTMULTIMEDIA=1) {
         !contains(QT_CONFIG, no-pkg-config):system(pkg-config --exists glib-2.0 gio-2.0 gstreamer-0.10): {
             DEFINES -= ENABLE_VIDEO=0
