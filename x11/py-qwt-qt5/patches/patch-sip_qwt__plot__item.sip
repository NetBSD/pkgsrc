$NetBSD: patch-sip_qwt__plot__item.sip,v 1.1 2024/05/11 20:54:12 adam Exp $

Builds against qwt-qt5 6.1.6
https://github.com/GauiStori/PyQt-Qwt/pull/22

--- sip/qwt_plot_item.sip.orig	2024-05-11 20:04:32.848763543 +0000
+++ sip/qwt_plot_item.sip
@@ -52,8 +52,8 @@ public:
         //! For QwtPlotSpectrogram
         Rtti_PlotSpectrogram,
 
-        //! For QwtPlotSvgItem
-        Rtti_PlotSVG,
+        //! For QwtPlotGraphicItem, QwtPlotSvgItem
+        Rtti_PlotGraphic,
 
         //! For QwtPlotTradingCurve
         Rtti_PlotTradingCurve,
@@ -73,7 +73,10 @@ public:
         //! For QwtPlotZoneItem
         Rtti_PlotZone,
 
-        /*! 
+        //! For QwtPlotVectorField
+        Rtti_PlotVectorField,
+
+        /*!
            Values >= Rtti_PlotUserItem are reserved for plot items
            not implemented in the Qwt library.
          */
@@ -234,11 +237,11 @@ public:
 
     virtual QList<QwtLegendData> legendData() const;
 
-/*    virtual QwtGraphic legendIcon( int index, const QSizeF  & ) const;
+    virtual QwtGraphic legendIcon( int index, const QSizeF  & ) const;
 
 protected:
     QwtGraphic defaultIcon( const QBrush &, const QSizeF & ) const;
-*/
+
 private:
     // Disabled copy constructor and operator=
     QwtPlotItem( const QwtPlotItem & );
