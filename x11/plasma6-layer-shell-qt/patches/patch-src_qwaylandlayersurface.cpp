$NetBSD: patch-src_qwaylandlayersurface.cpp,v 1.1 2025/07/07 01:41:21 gutteridge Exp $

Fix build with Qt 6 >= 6.9.
https://github.com/KDE/layer-shell-qt/commit/368cf2dd374ce104cbbe1fa356991db2e238c640

--- src/qwaylandlayersurface.cpp.orig	2024-05-21 16:48:51.000000000 +0000
+++ src/qwaylandlayersurface.cpp
@@ -256,8 +256,10 @@ void QWaylandLayerSurface::sendExpose()
 {
 #if QT_VERSION < QT_VERSION_CHECK(6, 7, 0)
     window()->handleExpose(QRect(QPoint(), m_pendingSize));
-#else
+#elif QT_VERSION < QT_VERSION_CHECK(6, 9, 0)
     window()->sendRecursiveExposeEvent();
+#else
+    window()->updateExposure();
 #endif
 }
 
