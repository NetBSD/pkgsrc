$NetBSD: patch-sip_qwt__curve__fitter.sip,v 1.1 2024/05/11 20:54:12 adam Exp $

Builds against qwt-qt5 6.1.6
https://github.com/GauiStori/PyQt-Qwt/pull/22

--- sip/qwt_curve_fitter.sip.orig	2024-05-11 19:49:47.706766690 +0000
+++ sip/qwt_curve_fitter.sip
@@ -17,6 +17,25 @@ class QwtCurveFitter
 public:
     virtual ~QwtCurveFitter();
 
+    enum Mode
+    {
+        /*!
+           The fitting algorithm creates a polygon - the implementation
+           of fitCurvePath() simply wraps the polygon into a path.
+
+           \sa QwtWeedingCurveFitter
+         */
+        Polygon,
+
+        /*!
+           The fitting algorithm creates a painter path - the implementation
+           of fitCurve() extracts a polygon from the path.
+
+           \sa QwtSplineCurveFitter
+         */
+        Path
+    };
+
     /*!
         Find a curve which has the best fit to a series of data points
 
@@ -24,9 +43,10 @@ public:
         \return Curve points
      */
     virtual QPolygonF fitCurve( const QPolygonF &polygon ) const = 0;
+    virtual QPainterPath fitCurvePath( const QPolygonF& polygon ) const = 0;
 
 protected:
-    QwtCurveFitter();
+    explicit QwtCurveFitter( Mode mode );
 
 private:
     QwtCurveFitter( const QwtCurveFitter & );
@@ -39,49 +59,20 @@ private:
 class QwtSplineCurveFitter: public QwtCurveFitter
 {
 %TypeHeaderCode
-#include <qwt_curve_fitter.h>
+#include <qwt_spline_curve_fitter.h>
 %End
 
 public:
-    /*!
-      Spline type
-      The default setting is Auto
-      \sa setFitMode(), FitMode()
-     */
-    enum FitMode
-    {
-        /*!
-          Use the default spline algorithm for polygons with
-          increasing x values ( p[i-1] < p[i] ), otherwise use
-          a parametric spline algorithm.
-         */
-        Auto,
-
-        //! Use a default spline algorithm
-        Spline,
-
-        //! Use a parametric spline algorithm
-        ParametricSpline
-    };
-
     QwtSplineCurveFitter();
     virtual ~QwtSplineCurveFitter();
 
-    void setFitMode( FitMode );
-    FitMode fitMode() const;
-
-    void setSpline( const QwtSpline& );
-    //const QwtSpline &spline() const; FIXME. 
-    QwtSpline &spline();
-
-    void setSplineSize( int size );
-    int splineSize() const;
+    void setSpline( QwtSpline* );
+    //const QwtSpline* spline() const;
+    QwtSpline* spline();
 
     virtual QPolygonF fitCurve( const QPolygonF & ) const;
+    virtual QPainterPath fitCurvePath( const QPolygonF& ) const;
 
-private:
-    QPolygonF fitSpline( const QPolygonF & ) const;
-    QPolygonF fitParametric( const QPolygonF & ) const;
 
     //class PrivateData;
     //PrivateData *d_data;
@@ -113,7 +104,7 @@ private:
 class QwtWeedingCurveFitter: public QwtCurveFitter
 {
 %TypeHeaderCode
-#include <qwt_curve_fitter.h>
+#include <qwt_weeding_curve_fitter.h>
 %End
 
 public:
