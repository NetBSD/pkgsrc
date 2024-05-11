$NetBSD: patch-sip_qwt__plot__seriesitem.sip,v 1.1 2024/05/11 20:54:12 adam Exp $

Builds against qwt-qt5 6.1.6
https://github.com/GauiStori/PyQt-Qwt/pull/22

--- sip/qwt_plot_seriesitem.sip.orig	2024-05-11 20:14:58.355036560 +0000
+++ sip/qwt_plot_seriesitem.sip
@@ -13,7 +13,7 @@ class QwtPlotSeriesItem: QwtPlotItem, Qw
 #include <qwt_plot_seriesitem.h>
 %End
 public:
-    explicit QwtPlotSeriesItem( const QString &title = QString::null );
+    explicit QwtPlotSeriesItem( const QString &title = QString() );
     //explicit QwtPlotSeriesItem( const QwtText &title );
     virtual ~QwtPlotSeriesItem();
     void setOrientation( Qt::Orientation );
