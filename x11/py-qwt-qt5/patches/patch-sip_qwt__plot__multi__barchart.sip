$NetBSD: patch-sip_qwt__plot__multi__barchart.sip,v 1.1 2024/05/11 20:54:12 adam Exp $

Builds against qwt-qt5 6.1.6
https://github.com/GauiStori/PyQt-Qwt/pull/22

--- sip/qwt_plot_multi_barchart.sip.orig	2024-05-11 20:19:43.721112694 +0000
+++ sip/qwt_plot_multi_barchart.sip
@@ -21,7 +21,7 @@ public:
         Stacked
     };
 
-    explicit QwtPlotMultiBarChart( const QString &title = QString::null );
+    explicit QwtPlotMultiBarChart( const QString &title = QString() );
     explicit QwtPlotMultiBarChart( const QwtText &title );
 
     virtual ~QwtPlotMultiBarChart();
