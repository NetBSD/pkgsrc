$NetBSD: patch-sip_qwt__color__map.sip,v 1.1 2024/05/11 20:54:12 adam Exp $

Builds against qwt-qt5 6.1.6
https://github.com/GauiStori/PyQt-Qwt/pull/22

--- sip/qwt_color_map.sip.orig	2020-12-27 08:53:37.000000000 +0000
+++ sip/qwt_color_map.sip
@@ -1,4 +1,4 @@
-/* 
+/******************************************************************************
  * python-qwt. Python wrapper for the Qwt Widget Library
  * Copyright (C) 1997   Josef Wilgen
  * Copyright (C) 2002   Uwe Rathmann
@@ -13,7 +13,7 @@ class QwtColorMap
 %TypeHeaderCode
 #include <qwt_color_map.h>
 %End
-public:
+  public:
     enum Format
     {
         RGB,
@@ -23,15 +23,19 @@ public:
     QwtColorMap( Format = QwtColorMap::RGB );
     virtual ~QwtColorMap();
 
+    void setFormat( Format );
     Format format() const;
-    virtual QRgb rgb( const QwtInterval &interval, double value ) const = 0;
-    virtual unsigned char colorIndex( const QwtInterval &interval, double value ) const = 0;
+    virtual QRgb rgb( const QwtInterval& interval, double value ) const = 0;
+    virtual uint colorIndex( int numColors, const QwtInterval& interval, double value ) const;
 
-    QColor color( const QwtInterval &, double value ) const;
-    virtual QVector<QRgb> colorTable( const QwtInterval & ) const;
+    QColor color( const QwtInterval&, double value ) const;
+    virtual QVector< QRgb > colorTable( int ) const;
+    virtual QVector< QRgb > colorTable256() const;
 
-//private:
-//    Format d_format;
+private:
+    QwtColorMap( const QwtColorMap & );
+
+//    Format m_format;
 };
 
 class QwtLinearColorMap: QwtColorMap
@@ -39,7 +43,7 @@ class QwtLinearColorMap: QwtColorMap
 %TypeHeaderCode
 #include <qwt_color_map.h>
 %End
-public:
+  public:
     enum Mode
     {
         FixedColors,
@@ -47,33 +51,33 @@ public:
     };
 
     QwtLinearColorMap( Format = QwtColorMap::RGB );
-    QwtLinearColorMap( const QColor &from, const QColor &to, 
-                       Format = QwtColorMap::RGB );
+    QwtLinearColorMap( const QColor& from, const QColor& to,
+        Format = QwtColorMap::RGB );
 
     virtual ~QwtLinearColorMap();
 
     void setMode( Mode );
     Mode mode() const;
 
-    void setColorInterval( const QColor &color1, const QColor &color2 );
+    void setColorInterval( const QColor& color1, const QColor& color2 );
     void addColorStop( double value, const QColor& );
-    QVector<double> colorStops() const;
+    QVector< double > colorStops() const;
 
     QColor color1() const;
     QColor color2() const;
 
-    virtual QRgb rgb( const QwtInterval &, double value ) const;
-    virtual unsigned char colorIndex( const QwtInterval &, double value ) const;
+    virtual QRgb rgb( const QwtInterval&,
+        double value ) const;
+
+    virtual uint colorIndex( int numColors,
+        const QwtInterval&, double value ) const;
 
     class ColorStops;
 
-private:
-    // Disabled copy constructor and operator=
+  private:
     QwtLinearColorMap( const QwtLinearColorMap & );
-    //QwtLinearColorMap &operator=( const QwtLinearColorMap & );
-
-    //class PrivateData;
-    //PrivateData *d_data;
+//    class PrivateData;
+//    PrivateData* m_data;
 };
 
 class QwtAlphaColorMap: QwtColorMap
@@ -81,42 +85,92 @@ class QwtAlphaColorMap: QwtColorMap
 %TypeHeaderCode
 #include <qwt_color_map.h>
 %End
-public:
-    QwtAlphaColorMap( const QColor & = QColor( Qt::gray ) );
+  public:
+    QwtAlphaColorMap( const QColor& = QColor( Qt::gray ) );
     virtual ~QwtAlphaColorMap();
 
-    void setColor( const QColor & );
+    void setAlphaInterval( int alpha1, int alpha2 );
+
+    int alpha1() const;
+    int alpha2() const;
+
+    void setColor( const QColor& );
     QColor color() const;
 
-    virtual QRgb rgb( const QwtInterval &, double value ) const;
+    virtual QRgb rgb( const QwtInterval&,
+        double value ) const;
 
-private:
+  private:
     QwtAlphaColorMap( const QwtAlphaColorMap & );
-    //QwtAlphaColorMap &operator=( const QwtAlphaColorMap & );
-
-    virtual unsigned char colorIndex( const QwtInterval &, double value ) const;
+//    class PrivateData;
+//    PrivateData* m_data;
+};
 
-    //class PrivateData;
-    //PrivateData *d_data;
+class QwtHueColorMap : QwtColorMap
+{
+%TypeHeaderCode
+#include <qwt_color_map.h>
+%End
+  public:
+    QwtHueColorMap( Format = QwtColorMap::RGB );
+    virtual ~QwtHueColorMap();
+
+    void setHueInterval( int hue1, int hue2 ); // direction ?
+    void setSaturation( int saturation );
+    void setValue( int value );
+    void setAlpha( int alpha );
+
+    int hue1() const;
+    int hue2() const;
+    int saturation() const;
+    int value() const;
+    int alpha() const;
+
+    virtual QRgb rgb( const QwtInterval&,
+        double value ) const;
+
+  private:
+    QwtHueColorMap( const QwtHueColorMap & );
+//    class PrivateData;
+//    PrivateData* m_data;
 };
 
+class QwtSaturationValueColorMap : QwtColorMap
+{
+%TypeHeaderCode
+#include <qwt_color_map.h>
+%End
+  public:
+    QwtSaturationValueColorMap();
+    virtual ~QwtSaturationValueColorMap();
+
+    void setHue( int hue );
+    void setSaturationInterval( int sat1, int sat2 );
+    void setValueInterval( int value1, int value2 );
+    void setAlpha( int alpha );
+
+    int hue() const;
+    int saturation1() const;
+    int saturation2() const;
+    int value1() const;
+    int value2() const;
+    int alpha() const;
+
+    virtual QRgb rgb( const QwtInterval&,
+        double value ) const;
+
+  private:
+    QwtSaturationValueColorMap( const QwtSaturationValueColorMap & );
+//    class PrivateData;
+//    PrivateData* m_data;
+};
 
-/*inline QColor QwtColorMap::color(
-    const QwtInterval &interval, double value ) const
+/*inline QColor QwtColorMap::color( const QwtInterval& interval, double value ) const
 {
-    if ( d_format == RGB )
-    {
-        return QColor::fromRgba( rgb( interval, value ) );
-    }
-    else
-    {
-        const unsigned int index = colorIndex( interval, value );
-        return colorTable( interval )[index]; // slow
-    }
+    return QColor::fromRgba( rgb( interval, value ) );
 }
 
 inline QwtColorMap::Format QwtColorMap::format() const
 {
-    return d_format;
+    return m_format;
 }*/
-
