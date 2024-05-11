$NetBSD: patch-sip_qwt__text.sip,v 1.1 2024/05/11 20:54:13 adam Exp $

Builds against qwt-qt5 6.1.6
https://github.com/GauiStori/PyQt-Qwt/pull/22

--- sip/qwt_text.sip.orig	2024-05-11 19:47:18.813705205 +0000
+++ sip/qwt_text.sip
@@ -42,7 +42,7 @@ public:
     typedef QFlags<QwtText::LayoutAttribute> LayoutAttributes;
 
     QwtText( const QwtText & );
-    QwtText( const QString & = QString::null, QwtText::TextFormat textFormat = AutoText );
+    QwtText( const QString & = QString(), QwtText::TextFormat textFormat = AutoText );
     ~QwtText();
 
     bool operator==( const QwtText & ) const;
