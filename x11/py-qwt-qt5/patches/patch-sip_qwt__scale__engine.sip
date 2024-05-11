$NetBSD: patch-sip_qwt__scale__engine.sip,v 1.1 2024/05/11 20:54:13 adam Exp $

Builds against qwt-qt5 6.1.6
https://github.com/GauiStori/PyQt-Qwt/pull/22

--- sip/qwt_scale_engine.sip.orig	2024-05-11 19:46:34.398837955 +0000
+++ sip/qwt_scale_engine.sip
@@ -111,7 +111,9 @@ protected:
 
     QwtInterval buildInterval( double v ) const;
 
-/*private:
+private:
+    QwtScaleEngine( const QwtScaleEngine & );
+/*
     class PrivateData;
     PrivateData *d_data;*/
 };
