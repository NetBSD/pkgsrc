$NetBSD: patch-sip_qwt__plot.sip,v 1.1 2024/05/11 20:54:12 adam Exp $

Builds against qwt-qt5 6.1.6
https://github.com/GauiStori/PyQt-Qwt/pull/22

--- sip/qwt_plot.sip.orig	2020-12-27 08:53:37.000000000 +0000
+++ sip/qwt_plot.sip
@@ -8,10 +8,14 @@
  * modify it under the terms of the Qwt License, Version 1.0
  *****************************************************************************/
 
+typedef int QwtAxisId;
+
 class QwtPlot: QFrame , QwtPlotDict
 {
 %TypeHeaderCode
 #include <qwt_plot_item.h>
+#include <qwt_axis.h>
+#include <qwt_axis_id.h>
 %End
 public:
     //! \brief Axis index
@@ -58,104 +62,109 @@ public:
 
     virtual ~QwtPlot();
 
-    void applyProperties( const QString & );
-    QString grabProperties() const;
+    //void applyProperties( const QString & );
+    //QString grabProperties() const;
 
     void setAutoReplot( bool = true );
     bool autoReplot() const;
 
     // Layout
 
-    void setPlotLayout( QwtPlotLayout * );
+    void setPlotLayout( QwtPlotLayout* );
 
-    QwtPlotLayout *plotLayout();
-    //const QwtPlotLayout *plotLayout() const;
+    QwtPlotLayout* plotLayout();
+    //const QwtPlotLayout* plotLayout() const;
 
     // Title
 
-    void setTitle( const QString & );
-    void setTitle( const QwtText &t );
+    void setTitle( const QString& );
+    void setTitle( const QwtText& );
     QwtText title() const;
 
-    QwtTextLabel *titleLabel();
-    //const QwtTextLabel *titleLabel() const;
+    QwtTextLabel* titleLabel();
+    //const QwtTextLabel* titleLabel() const;
 
     // Footer
 
-    void setFooter( const QString & );
-    void setFooter( const QwtText &t );
+    void setFooter( const QString& );
+    void setFooter( const QwtText& );
     QwtText footer() const;
 
-    QwtTextLabel *footerLabel();
-    //const QwtTextLabel *footerLabel() const;
+    QwtTextLabel* footerLabel();
+    //const QwtTextLabel* footerLabel() const;
 
     // Canvas
 
-    void setCanvas( QWidget * /Transfer/);
+    void setCanvas( QWidget* /Transfer/);
 
-    QWidget *canvas();
-    //const QWidget *canvas() const;
+    QWidget* canvas();
+    //const QWidget* canvas() const;
 
-    void setCanvasBackground( const QBrush & );
+    void setCanvasBackground( const QBrush& );
     QBrush canvasBackground() const;
 
-    virtual QwtScaleMap canvasMap( int axisId ) const;
+    virtual QwtScaleMap canvasMap( QwtAxisId ) const;
 
-    double invTransform( int axisId, int pos ) const;
-    double transform( int axisId, double value ) const;
+    double invTransform( QwtAxisId, double pos ) const;
+    double transform( QwtAxisId, double value ) const;
 
     // Axes
 
-    QwtScaleEngine *axisScaleEngine( int axisId );
-    //const QwtScaleEngine *axisScaleEngine( int axisId ) const;
-    void setAxisScaleEngine( int axisId, QwtScaleEngine * /Transfer/);
+    bool isAxisValid( QwtAxisId ) const;
+
+    void setAxisVisible( QwtAxisId, bool on = true );
+    bool isAxisVisible( QwtAxisId ) const;
+
+    // Axes data
 
-    void setAxisAutoScale( int axisId, bool on = true );
-    bool axisAutoScale( int axisId ) const;
+    QwtScaleEngine* axisScaleEngine( QwtAxisId );
+    //const QwtScaleEngine* axisScaleEngine( QwtAxisId ) const;
+    void setAxisScaleEngine( QwtAxisId, QwtScaleEngine* /Transfer/);
 
-    void enableAxis( int axisId, bool tf = true );
-    bool axisEnabled( int axisId ) const;
 
-    void setAxisFont( int axisId, const QFont &f );
-    QFont axisFont( int axisId ) const;
+    void setAxisAutoScale( QwtAxisId, bool on = true );
+    bool axisAutoScale( QwtAxisId ) const;
 
-    void setAxisScale( int axisId, double min, double max, double step = 0 );
-    void setAxisScaleDiv( int axisId, const QwtScaleDiv & );
-    void setAxisScaleDraw( int axisId, QwtScaleDraw *  /Transfer/);
+    void setAxisFont( QwtAxisId, const QFont& );
+    QFont axisFont( QwtAxisId ) const;
 
-    double axisStepSize( int axisId ) const;
-    QwtInterval axisInterval( int axisId ) const;
+    void setAxisScale( QwtAxisId, double min, double max, double stepSize = 0 );
+    void setAxisScaleDiv( QwtAxisId, const QwtScaleDiv& );
+    void setAxisScaleDraw( QwtAxisId, QwtScaleDraw* /Transfer/);
 
-    const QwtScaleDiv &axisScaleDiv( int axisId ) const;
+    double axisStepSize( QwtAxisId ) const;
+    QwtInterval axisInterval( QwtAxisId ) const;
+    const QwtScaleDiv& axisScaleDiv( QwtAxisId ) const;
 
-    //const QwtScaleDraw *axisScaleDraw( int axisId ) const;
-    QwtScaleDraw *axisScaleDraw( int axisId );
+    //const QwtScaleDraw* axisScaleDraw( QwtAxisId ) const;
+    QwtScaleDraw* axisScaleDraw( QwtAxisId );
 
-    //const QwtScaleWidget *axisWidget( int axisId ) const;
-    QwtScaleWidget *axisWidget( int axisId );
+    //const QwtScaleWidget* axisWidget( QwtAxisId ) const;
+    QwtScaleWidget* axisWidget( QwtAxisId );
 
-    void setAxisLabelAlignment( int axisId, Qt::Alignment );
-    void setAxisLabelRotation( int axisId, double rotation );
+    void setAxisLabelAlignment( QwtAxisId, Qt::Alignment );
+    void setAxisLabelRotation( QwtAxisId, double rotation );
 
-    void setAxisTitle( int axisId, const QString & );
-    void setAxisTitle( int axisId, const QwtText & );
-    QwtText axisTitle( int axisId ) const;
+    void setAxisTitle( QwtAxisId, const QString& );
+    void setAxisTitle( QwtAxisId, const QwtText& );
+    QwtText axisTitle( QwtAxisId ) const;
 
-    void setAxisMaxMinor( int axisId, int maxMinor );
-    int axisMaxMinor( int axisId ) const;
+    void setAxisMaxMinor( QwtAxisId, int maxMinor );
+    int axisMaxMinor( QwtAxisId ) const;
 
-    void setAxisMaxMajor( int axisId, int maxMajor );
-    int axisMaxMajor( int axisId ) const;
+    void setAxisMaxMajor( QwtAxisId, int maxMajor );
+    int axisMaxMajor( QwtAxisId ) const;
 
     // Legend
 
-    void insertLegend( QwtAbstractLegend * /Transfer/, LegendPosition = QwtPlot::RightLegend, double ratio = -1.0 );
+    void insertLegend( QwtAbstractLegend* /Transfer/,
+        LegendPosition = QwtPlot::RightLegend, double ratio = -1.0 );
 
-    QwtAbstractLegend *legend();
-    //const QwtAbstractLegend *legend() const;
+    QwtAbstractLegend* legend();
+    //const QwtAbstractLegend* legend() const;
 
     void updateLegend();
-    void updateLegend( const QwtPlotItem *);
+    void updateLegend( const QwtPlotItem* );
 
     // Misc
 
@@ -163,72 +172,71 @@ public:
     virtual QSize minimumSizeHint() const;
 
     virtual void updateLayout();
-    virtual void drawCanvas( QPainter * );
+    virtual void drawCanvas( QPainter* );
 
     void updateAxes();
     void updateCanvasMargins();
 
-    /*virtual void getCanvasMarginsHint( 
-        const QwtScaleMap maps[], const QRectF &canvasRect,
-        double &left, double &top, double &right, double &bottom) const;*/
+    virtual void getCanvasMarginsHint(
+        const QwtScaleMap *, const QRectF& canvasRect,
+        double& left, double& top, double& right, double& bottom) const;
 
-    virtual bool event( QEvent * );
-    virtual bool eventFilter( QObject *, QEvent *);
+    virtual bool event( QEvent* );
+    virtual bool eventFilter( QObject*, QEvent* );
 
-    /*virtual void drawItems( QPainter *, const QRectF &,
-        const QwtScaleMap maps[axisCnt] ) const;*/
+    virtual void drawItems( QPainter*, const QRectF&,
+        const QwtScaleMap* ) const;
 
-    virtual QVariant itemToInfo( QwtPlotItem *) const;
-    virtual QwtPlotItem *infoToItem( const QVariant & ) const;
+    virtual QVariant itemToInfo( QwtPlotItem* ) const;
+    virtual QwtPlotItem* infoToItem( const QVariant& ) const;
 
 signals:
     /*!
-      A signal indicating, that an item has been attached/detached
+       A signal indicating, that an item has been attached/detached
 
-      \param plotItem Plot item
-      \param on Attached/Detached
+       \param plotItem Plot item
+       \param on Attached/Detached
      */
-    void itemAttached( QwtPlotItem *plotItem, bool on );
+    void itemAttached( QwtPlotItem* plotItem, bool on );
 
     /*!
-      A signal with the attributes how to update 
-      the legend entries for a plot item.
+       A signal with the attributes how to update
+       the legend entries for a plot item.
 
-      \param itemInfo Info about a plot item, build from itemToInfo()
-      \param data Attributes of the entries ( usually <= 1 ) for
+       \param itemInfo Info about a plot item, build from itemToInfo()
+       \param data Attributes of the entries ( usually <= 1 ) for
                   the plot item.
 
-      \sa itemToInfo(), infoToItem(), QwtAbstractLegend::updateLegend()
+       \sa itemToInfo(), infoToItem(), QwtAbstractLegend::updateLegend()
      */
-    void legendDataChanged( const QVariant &itemInfo, 
-        const QList<QwtLegendData> &data );
+    void legendDataChanged( const QVariant& itemInfo,
+        const QList< QwtLegendData >& data );
 
 public slots:
     virtual void replot();
     void autoRefresh();
 
 protected:
-    static bool axisValid( int axisId );
 
-    virtual void resizeEvent( QResizeEvent *e );
+    virtual void resizeEvent( QResizeEvent* );
 
 private slots:
-    void updateLegendItems( const QVariant &itemInfo,
-        const QList<QwtLegendData> &data );
+    void updateLegendItems( const QVariant& itemInfo,
+        const QList< QwtLegendData >& legendData );
 
 /*private:
     friend class QwtPlotItem;
-    void attachItem( QwtPlotItem *, bool );
+    void attachItem( QwtPlotItem*, bool );
 
     void initAxesData();
     void deleteAxesData();
     void updateScaleDiv();
 
-    void initPlot( const QwtText &title );
+    void initPlot( const QwtText& title );
 
-    class AxisData;
-    AxisData *d_axisData[axisCnt];
+    class ScaleData;
+    ScaleData* m_scaleData;
 
     class PrivateData;
-    PrivateData *d_data;*/
+    PrivateData* m_data;*/
 };
