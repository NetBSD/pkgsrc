$NetBSD: patch-nucleo_network_xmpp_XmppConnection.cxx,v 1.1 2012/07/09 19:06:54 joerg Exp $

--- nucleo/network/xmpp/XmppConnection.cxx.orig	2012-07-06 13:25:25.000000000 +0000
+++ nucleo/network/xmpp/XmppConnection.cxx
@@ -616,14 +616,16 @@ namespace nucleo {
   // -----------------------------------------------------------------------------------------
 
   XmlParser::InBox::iterator
-  XmppConnection::waitFor(long milliseconds, cistring tagname, ...) {
+  XmppConnection::waitFor(long milliseconds, const char *tagname_, ...) {
     if (!connection) return inbox.end() ;
 
+    cistring tagname(tagname_);
+
     waiting++ ; // Stop notifying observers right now
 
     std::list<XmlStructure::KeyValuePair> attribs ;
     va_list ap ;
-    va_start(ap,tagname) ;
+    va_start(ap,tagname_) ;
     for (char *key=va_arg(ap, char*); key; key=va_arg(ap, char*))
 	 attribs.push_back(XmlStructure::KeyValuePair(key, va_arg(ap, char*))) ;
     va_end(ap) ;
