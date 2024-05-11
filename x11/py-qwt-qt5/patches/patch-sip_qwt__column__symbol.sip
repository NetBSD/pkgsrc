$NetBSD: patch-sip_qwt__column__symbol.sip,v 1.1 2024/05/11 20:54:12 adam Exp $

Builds against qwt-qt5 6.1.6
https://github.com/GauiStori/PyQt-Qwt/pull/22

--- sip/qwt_column_symbol.sip.orig	2024-05-11 19:48:54.362021705 +0000
+++ sip/qwt_column_symbol.sip
@@ -143,4 +143,6 @@ public:
 protected:
     void drawBox( QPainter * /Transfer/, const QwtColumnRect & ) const;
 
+private:
+     QwtColumnSymbol( const QwtColumnSymbol & );
 };
