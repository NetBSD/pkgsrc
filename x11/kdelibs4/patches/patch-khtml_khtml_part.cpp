$NetBSD: patch-khtml_khtml_part.cpp,v 1.1 2011/04/11 10:11:42 markd Exp $

Fix for CVE-2011-1168.

--- khtml/khtml_part.cpp.orig	2010-08-27 08:09:16.000000000 +0000
+++ khtml/khtml_part.cpp
@@ -1803,7 +1803,10 @@ void KHTMLPart::htmlError( int errorCode
   stream >> errorName >> techName >> description >> causes >> solutions;
 
   QString url, protocol, datetime;
-  url = Qt::escape( reqUrl.prettyUrl() );
+
+  // This is somewhat confusing, but we have to escape the externally-
+  // controlled URL twice: once for i18n, and once for HTML.
+  url = Qt::escape( Qt::escape( reqUrl.prettyUrl() ) );
   protocol = reqUrl.protocol();
   datetime = KGlobal::locale()->formatDateTime( QDateTime::currentDateTime(),
                                                 KLocale::LongDate );
