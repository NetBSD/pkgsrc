$NetBSD: patch-sip_qwt__transform.sip,v 1.3 2024/05/11 20:54:13 adam Exp $

Builds against qwt-qt5 6.1.6
https://github.com/GauiStori/PyQt-Qwt/pull/22

--- sip/qwt_transform.sip.orig	2024-05-11 19:42:44.185023847 +0000
+++ sip/qwt_transform.sip
@@ -45,6 +45,9 @@ public:
 
     //! Virtualized copy operation
     virtual QwtTransform *copy() const = 0;
+
+private:
+     QwtTransform( const QwtTransform & );
 };
 
 /*!
