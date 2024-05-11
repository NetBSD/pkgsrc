$NetBSD: patch-sip_qwt__point__data.sip,v 1.1 2024/05/11 20:54:13 adam Exp $

Builds against qwt-qt5 6.1.6
https://github.com/GauiStori/PyQt-Qwt/pull/22

--- sip/qwt_point_data.sip.orig	2024-05-11 20:12:06.870168546 +0000
+++ sip/qwt_point_data.sip
@@ -8,16 +8,35 @@
  * modify it under the terms of the Qwt License, Version 1.0
  *****************************************************************************/
 
-class QwtPointArrayData: QwtSeriesDataQPointF
+class QwtPointArrayDataDouble: QwtPointSeriesData
 {
 %TypeHeaderCode
+#include <qwt_series_data.h>
 #include <qwt_point_data.h>
+typedef QwtSeriesData<QPointF> QwtSeriesDataQPointF;
+typedef QwtArraySeriesData<QPointF> QwtArraySeriesDataQPointF;
+typedef QwtPointArrayData<double> QwtPointArrayDataDouble;
 %End
 
 public:
-    QwtPointArrayData( const QVector<double> &x, const QVector<double> &y );
-    //QwtPointArrayData( const double *x, const double *y, size_t size ); FIXME
-
+    QwtPointArrayDataDouble( const QVector<double> &x, const QVector<double> &y );
+    
+      	
+    QwtPointArrayDataDouble(QVector<double> &,QVector<double> &)[( const double *x, const double *y, size_t size )];
+    
+    %MethodCode
+         //QVector<double> d_x;
+         //QVector<double> d_y;
+         //size_t size;
+         //const double*x;
+	//const double*y;
+	//d_x.resize( size );
+    	//::memcpy( d_x.data(), x, size * sizeof( double ) );
+
+    	//d_y.resize( size );
+    	//::memcpy( d_y.data(), y, size * sizeof( double ) );
+    %End
+     
     virtual QRectF boundingRect() const;
 
     virtual size_t size() const;
@@ -33,44 +52,65 @@ public:
 
 /*!
   \brief Data class containing two pointers to memory blocks of doubles.
- */
-/*class QwtCPointerData: QwtSeriesDataQPointF
+*/ 
+class QwtCPointerDataDouble: QwtPointSeriesData
 {
 %TypeHeaderCode
+#include <qwt_series_data.h>
 #include <qwt_point_data.h>
+typedef QwtSeriesData<QPointF> QwtSeriesDataQPointF;
+typedef QwtArraySeriesData<QPointF> QwtArraySeriesDataQPointF;
+typedef QwtCPointerData<double> QwtCPointerDataDouble;
 %End
 
 public:
-    //QwtCPointerData( const double *x, const double *y, size_t size ); FIXME
-
+    QwtCPointerDataDouble(SIP_PYLIST,SIP_PYLIST,size_t size)[( const double *x, const double *y, size_t size )];
+    %MethodCode
+    //const double *d_x;
+    //const double *d_y;
+    //size_t d_size;
+    //size_t size;
+    //const double*x;
+    //const double*y;
+    //d_x = x ;
+    //d_y = y ;
+    //d_size =  size ;	
+    %End 
+    
+    
     virtual QRectF boundingRect() const;
     virtual size_t size() const;
     virtual QPointF sample( size_t i ) const;
 
-    const double *xData() const;
-    const double *yData() const;
-*/
+    //const double *xData() const;
+    //const double *yData() const;
+
+    const SIP_PYLIST xData() const;
+     %MethodCode
+	//const double *d_x;
+	//return d_x;	
+    %End
+     const SIP_PYLIST yData() const;	
+      %MethodCode
+	//const double *d_y;
+	//return d_y;	
+    %End
+	
+
+
 /*private:
     const double *d_x;
     const double *d_y;
     size_t d_size;*/
-//};
-
-
-/*class SinusData: QwtSyntheticPointData FIXME
-{
-%TypeHeaderCode
-#include <qwt_point_data.h>
-%End
-public:
-    SinusData();
-    virtual double y( double x ) const;
-};*/
+};
 
-class QwtSyntheticPointData: QwtSeriesDataQPointF
+class QwtSyntheticPointData: QwtPointSeriesData
 {
 %TypeHeaderCode
+#include <qwt_series_data.h>
 #include <qwt_point_data.h>
+typedef QwtSeriesData<QPointF> QwtSeriesDataQPointF;
+typedef QwtArraySeriesData<QPointF> QwtArraySeriesDataQPointF;
 %End
 public:
     QwtSyntheticPointData( size_t size,
@@ -91,6 +131,7 @@ public:
     virtual void setRectOfInterest( const QRectF & );
     QRectF rectOfInterest() const;
 
+
 /*private:
     size_t d_size;
     QwtInterval d_interval;
@@ -98,3 +139,6 @@ public:
     QwtInterval d_intervalOfInterest;*/
 };
 
+
+
+
