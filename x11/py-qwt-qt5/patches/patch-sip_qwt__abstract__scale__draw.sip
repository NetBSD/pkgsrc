$NetBSD: patch-sip_qwt__abstract__scale__draw.sip,v 1.1 2024/05/11 20:54:12 adam Exp $

Builds against qwt-qt5 6.1.6
https://github.com/GauiStori/PyQt-Qwt/pull/22

--- sip/qwt_abstract_scale_draw.sip.orig	2024-05-11 19:33:48.206196535 +0000
+++ sip/qwt_abstract_scale_draw.sip
@@ -54,8 +54,8 @@ public:
     void setSpacing( double margin );
     double spacing() const;
 
-    void setPenWidth( int width );
-    int penWidth() const;
+    void setPenWidthF( int width );
+    int penWidthF() const;
 
     virtual void draw( QPainter *, const QPalette & ) const;
 
