$NetBSD: patch-sip_qwt__compass__rose.sip,v 1.1 2024/05/11 20:54:12 adam Exp $

Builds against qwt-qt5 6.1.6
https://github.com/GauiStori/PyQt-Qwt/pull/22

--- sip/qwt_compass_rose.sip.orig	2024-05-11 19:38:00.537539161 +0000
+++ sip/qwt_compass_rose.sip
@@ -41,7 +41,8 @@ public:
         const QPointF &center, double radius, double north,
         QPalette::ColorGroup colorGroup = QPalette::Active ) const = 0;
         
-//private:
+private:
+    QwtCompassRose( const QwtCompassRose & );
 //    QPalette d_palette;
 };
 
