$NetBSD: patch-sip_qwt__plot__zoomer.sip,v 1.1 2024/05/11 20:54:12 adam Exp $

Builds against qwt-qt5 6.1.6
https://github.com/GauiStori/PyQt-Qwt/pull/22

--- sip/qwt_plot_zoomer.sip.orig	2024-05-11 20:13:14.838718190 +0000
+++ sip/qwt_plot_zoomer.sip
@@ -25,7 +25,7 @@ public:
     QRectF zoomBase() const;
     QRectF zoomRect() const;
 
-    virtual void setAxis( int xAxis, int yAxis );
+    virtual void setAxes( int xAxis, int yAxis );
 
     void setMaxStackDepth( int );
     int maxStackDepth() const;
