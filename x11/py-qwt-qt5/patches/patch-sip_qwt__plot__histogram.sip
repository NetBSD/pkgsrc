$NetBSD: patch-sip_qwt__plot__histogram.sip,v 1.1 2024/05/11 20:54:12 adam Exp $

Builds against qwt-qt5 6.1.6
https://github.com/GauiStori/PyQt-Qwt/pull/22

--- sip/qwt_plot_histogram.sip.orig	2024-05-11 19:58:26.497873265 +0000
+++ sip/qwt_plot_histogram.sip
@@ -23,7 +23,7 @@ public:
         UserStyle = 100
     };
 
-    explicit QwtPlotHistogram( const QString &title = QString::null );
+    explicit QwtPlotHistogram( const QString &title = QString() );
     //explicit QwtPlotHistogram( const QwtText &title );
     virtual ~QwtPlotHistogram();
 
