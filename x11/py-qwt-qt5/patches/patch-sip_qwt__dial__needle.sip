$NetBSD: patch-sip_qwt__dial__needle.sip,v 1.1 2024/05/11 20:54:12 adam Exp $

Builds against qwt-qt5 6.1.6
https://github.com/GauiStori/PyQt-Qwt/pull/22

--- sip/qwt_dial_needle.sip.orig	2024-05-11 19:41:39.926440299 +0000
+++ sip/qwt_dial_needle.sip
@@ -55,7 +55,8 @@ protected:
     virtual void drawKnob( QPainter *, double width, 
         const QBrush &, bool sunken ) const;
 
-//private:
+private:
+    QwtDialNeedle( const QwtDialNeedle & );
 //    QPalette d_palette;
 };
 
