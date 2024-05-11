$NetBSD: patch-sip_qwt__plot__layout.sip,v 1.1 2024/05/11 20:54:12 adam Exp $

Builds against qwt-qt5 6.1.6
https://github.com/GauiStori/PyQt-Qwt/pull/22

--- sip/qwt_plot_layout.sip.orig	2020-12-27 08:53:37.000000000 +0000
+++ sip/qwt_plot_layout.sip
@@ -41,9 +41,9 @@ public:
         //! Ignore the footer.
         IgnoreFooter = 0x20
     };
+    typedef QFlags<QwtPlotLayout::Option> Options;
 
     //! Layout options
-    //typedef QFlags<Option> Options;
 
     explicit QwtPlotLayout();
     virtual ~QwtPlotLayout();
@@ -68,8 +68,8 @@ public:
 
     virtual QSize minimumSizeHint( const QwtPlot * ) const;
 
-    /*virtual void activate( const QwtPlot *,
-        const QRectF &rect, Options options = 0x00 );*/
+    virtual void activate( const QwtPlot *,
+        const QRectF &rect, Options options );
 
     virtual void invalidate();
 
@@ -89,17 +89,19 @@ protected:
     void setScaleRect( int axis, const QRectF & );
     void setCanvasRect( const QRectF & );
 
-    //QRectF layoutLegend( Options options, const QRectF & ) const;
-    QRectF alignLegend( const QRectF &canvasRect,
-        const QRectF &legendRect ) const;
+    //QRectF layoutLegend( Option options, const QRectF & ) const;
+    //QRectF alignLegend( const QRectF &canvasRect,
+    //    const QRectF &legendRect ) const;
 
-    /*void expandLineBreaks( Options options, const QRectF &rect,
+    /*void expandLineBreaks( Option options, const QRectF &rect,
         int &dimTitle, int &dimFooter, int dimAxes[QwtPlot::axisCnt] ) const;
 
-    void alignScales( Options options, QRectF &canvasRect,
+    void alignScales( Option options, QRectF &canvasRect,
         QRectF scaleRect[QwtPlot::axisCnt] ) const;*/
 
-/*private:
+private:
+    QwtPlotLayout( const QwtPlotLayout & );
+/*
     class PrivateData;
 
     PrivateData *d_data;*/
