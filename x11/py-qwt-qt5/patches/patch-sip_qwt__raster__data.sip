$NetBSD: patch-sip_qwt__raster__data.sip,v 1.1 2024/05/11 20:54:13 adam Exp $

Builds against qwt-qt5 6.1.6
https://github.com/GauiStori/PyQt-Qwt/pull/22

--- sip/qwt_raster_data.sip.orig	2024-05-11 19:45:15.568368399 +0000
+++ sip/qwt_raster_data.sip
@@ -25,8 +25,7 @@ public:
     QwtRasterData();
     virtual ~QwtRasterData();
 
-    virtual void setInterval( Qt::Axis, const QwtInterval & );
-    const QwtInterval &interval(Qt::Axis) const;
+    virtual QwtInterval interval( Qt::Axis ) const = 0;
 
     virtual QRectF pixelHint( const QRectF & ) const;
 
