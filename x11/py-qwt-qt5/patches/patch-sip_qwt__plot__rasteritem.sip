$NetBSD: patch-sip_qwt__plot__rasteritem.sip,v 1.1 2024/05/11 20:54:12 adam Exp $

Builds against qwt-qt5 6.1.6
https://github.com/GauiStori/PyQt-Qwt/pull/22

--- sip/qwt_plot_rasteritem.sip.orig	2024-05-11 20:15:33.534745773 +0000
+++ sip/qwt_plot_rasteritem.sip
@@ -27,7 +27,7 @@ public:
 
     typedef QFlags<QwtPlotRasterItem::PaintAttribute> PaintAttributes;
 
-    explicit QwtPlotRasterItem( const QString& title = QString::null );
+    explicit QwtPlotRasterItem( const QString& title = QString() );
     explicit QwtPlotRasterItem( const QwtText& title );
     virtual ~QwtPlotRasterItem();
 
