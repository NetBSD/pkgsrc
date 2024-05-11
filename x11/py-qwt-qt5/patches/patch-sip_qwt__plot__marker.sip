$NetBSD: patch-sip_qwt__plot__marker.sip,v 1.1 2024/05/11 20:54:12 adam Exp $

Builds against qwt-qt5 6.1.6
https://github.com/GauiStori/PyQt-Qwt/pull/22

--- sip/qwt_plot_marker.sip.orig	2024-05-11 20:09:05.785552748 +0000
+++ sip/qwt_plot_marker.sip
@@ -35,7 +35,7 @@ public:
         Cross
     };
 
-    explicit QwtPlotMarker( const QString &title = QString::null );
+    explicit QwtPlotMarker( const QString &title = QString() );
     explicit QwtPlotMarker( const QwtText &title );
 
     virtual ~QwtPlotMarker();
