$NetBSD: patch-sip_qwt__plot__picker.sip,v 1.1 2024/05/11 20:54:12 adam Exp $

Builds against qwt-qt5 6.1.6
https://github.com/GauiStori/PyQt-Qwt/pull/22

--- sip/qwt_plot_picker.sip.orig	2024-05-11 20:19:09.494228953 +0000
+++ sip/qwt_plot_picker.sip
@@ -24,7 +24,7 @@ public:
     explicit QwtPlotPicker( int xAxis, int yAxis,
         RubberBand rubberBand, DisplayMode trackerMode, QWidget * /TransferThis/ );
 
-    virtual void setAxis( int xAxis, int yAxis );
+    virtual void setAxes( int xAxis, int yAxis );
 
     int xAxis() const;
     int yAxis() const;
