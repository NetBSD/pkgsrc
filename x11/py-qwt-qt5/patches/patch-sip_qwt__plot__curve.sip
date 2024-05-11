$NetBSD: patch-sip_qwt__plot__curve.sip,v 1.1 2024/05/11 20:54:12 adam Exp $

Builds against qwt-qt5 6.1.6
https://github.com/GauiStori/PyQt-Qwt/pull/22

--- sip/qwt_plot_curve.sip.orig	2024-05-11 19:56:29.609000676 +0000
+++ sip/qwt_plot_curve.sip
@@ -170,7 +170,7 @@ public:
     //! Paint attributes
     //typedef QFlags<PaintAttribute> PaintAttributes;
 
-    explicit QwtPlotCurve( const QString &title = QString::null);
+    explicit QwtPlotCurve( const QString &title = QString() );
     explicit QwtPlotCurve( const QwtText &title );
 
     virtual ~QwtPlotCurve();
