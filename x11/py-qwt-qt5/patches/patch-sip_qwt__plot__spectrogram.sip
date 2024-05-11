$NetBSD: patch-sip_qwt__plot__spectrogram.sip,v 1.1 2024/05/11 20:54:12 adam Exp $

Builds against qwt-qt5 6.1.6
https://github.com/GauiStori/PyQt-Qwt/pull/22

--- sip/qwt_plot_spectrogram.sip.orig	2024-05-11 20:14:11.671333252 +0000
+++ sip/qwt_plot_spectrogram.sip
@@ -31,7 +31,7 @@ public:
     //! Display modes
     typedef QFlags<QwtPlotSpectrogram::DisplayMode> DisplayModes;
 
-    explicit QwtPlotSpectrogram( const QString &title = QString::null );
+    explicit QwtPlotSpectrogram( const QString &title = QString() );
     virtual ~QwtPlotSpectrogram();
 
     void setDisplayMode( QwtPlotSpectrogram::DisplayMode, bool on = true );
