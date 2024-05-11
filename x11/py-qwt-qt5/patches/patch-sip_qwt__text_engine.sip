$NetBSD: patch-sip_qwt__text_engine.sip,v 1.1 2024/05/11 20:54:13 adam Exp $

Builds against qwt-qt5 6.1.6
https://github.com/GauiStori/PyQt-Qwt/pull/22

--- sip/qwt_text_engine.sip.orig	2024-05-11 20:10:54.539817875 +0000
+++ sip/qwt_text_engine.sip
@@ -24,6 +24,9 @@ public:
 
 protected:
     QwtTextEngine();
+
+private:
+    QwtTextEngine( const QwtTextEngine & );
 };
 
 class QwtPlainTextEngine: QwtTextEngine
