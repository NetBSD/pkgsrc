$NetBSD: patch-src_plugins_qpa_integration.cpp,v 1.1 2026/05/04 11:08:21 markd Exp $

Build with qt6.10.2
https://github.com/KDE/kwin/commit/d26749ec3653ae01e3a93fe0356d2fe33905b866

--- src/plugins/qpa/integration.cpp.orig	2025-11-04 14:59:51.000000000 +0000
+++ src/plugins/qpa/integration.cpp
@@ -88,17 +88,16 @@ bool Integration::hasCapability(Capabili
 {
     switch (cap) {
     case ThreadedPixmaps:
-        return true;
     case OpenGL:
-        return true;
-    case ThreadedOpenGL:
-        return false;
-    case BufferQueueingOpenGL:
-        return false;
     case MultipleWindows:
     case NonFullScreenWindows:
+#if QT_VERSION >= QT_VERSION_CHECK(6, 10, 2)
+    case OffscreenSurface:
+#endif
         return true;
+    case ThreadedOpenGL:
+    case BufferQueueingOpenGL:
     case RasterGLSurface:
         return false;
     default:
         return QPlatformIntegration::hasCapability(cap);
@@ -140,7 +139,7 @@ QPlatformWindow *Integration::createPlat
 
 QPlatformOffscreenSurface *Integration::createPlatformOffscreenSurface(QOffscreenSurface *surface) const
 {
-    return new OffscreenSurface(surface);
+    return new KWin::QPA::OffscreenSurface(surface);
 }
 
 QPlatformFontDatabase *Integration::fontDatabase() const
