$NetBSD: patch-sip_qwt__plot__barchart.sip,v 1.1 2024/05/11 20:54:12 adam Exp $

Builds against qwt-qt5 6.1.6
https://github.com/GauiStori/PyQt-Qwt/pull/22

--- sip/qwt_plot_barchart.sip.orig	2024-05-11 19:55:39.059591910 +0000
+++ sip/qwt_plot_barchart.sip
@@ -40,7 +40,7 @@ public:
         LegendBarTitles
     };
 
-    explicit QwtPlotBarChart( const QString &title = QString::null );
+    explicit QwtPlotBarChart( const QString &title = QString() );
     explicit QwtPlotBarChart( const QwtText &title );
 
     virtual ~QwtPlotBarChart();
