$NetBSD: patch-sip_qwt__spline.sip,v 1.1 2024/05/11 20:54:13 adam Exp $

Builds against qwt-qt5 6.1.6
https://github.com/GauiStori/PyQt-Qwt/pull/22

--- sip/qwt_spline.sip.orig	2024-05-11 20:09:56.560195066 +0000
+++ sip/qwt_spline.sip
@@ -15,40 +15,52 @@ class QwtSpline
 %End
 
 public:
-    //! Spline type
-    enum SplineType
+
+    enum BoundaryType
     {
-        //! A natural spline
-        Natural,
+        ConditionalBoundaries,
+        PeriodicPolygon,
+        ClosedPolygon
+    };
 
-        //! A periodic spline
-        Periodic
+    enum BoundaryPosition
+    {
+        AtBeginning,
+        AtEnd
     };
 
-    QwtSpline();
-    QwtSpline( const QwtSpline & );
+    enum BoundaryCondition
+    {
+        Clamped1,
+        Clamped2,
+        Clamped3,
+        LinearRunout
+    };
 
-    ~QwtSpline();
+    QwtSpline();
+    virtual ~QwtSpline();
 
-    //QwtSpline &operator=( const QwtSpline & );
+    void setParametrization( int type );
+    //void setParametrization( QwtSplineParametrization* );
+    //const QwtSplineParametrization* parametrization() const;
 
-    void setSplineType( SplineType );
-    SplineType splineType() const;
+    void setBoundaryType( BoundaryType );
+    BoundaryType boundaryType() const;
 
-    bool setPoints( const QPolygonF& points );
-    QPolygonF points() const;
+    void setBoundaryValue( BoundaryPosition, double value );
+    double boundaryValue( BoundaryPosition ) const;
 
-    void reset();
+    void setBoundaryCondition( BoundaryPosition, int condition );
+    int boundaryCondition( BoundaryPosition ) const;
 
-    bool isValid() const;
-    double value( double x ) const;
+    void setBoundaryConditions( int condition,
+        double valueBegin = 0.0, double valueEnd = 0.0 );
 
-    const QVector<double> &coefficientsA() const;
-    const QVector<double> &coefficientsB() const;
-    const QVector<double> &coefficientsC() const;
+    virtual QPolygonF polygon( const QPolygonF&, double tolerance ) const;
+    virtual QPainterPath painterPath( const QPolygonF& ) const = 0;
 
-protected:
-    bool buildNaturalSpline( const QPolygonF & );
-    bool buildPeriodicSpline( const QPolygonF & );
+    virtual uint locality() const;
 
+private:
+    QwtSpline( const QwtSpline & );
 };
