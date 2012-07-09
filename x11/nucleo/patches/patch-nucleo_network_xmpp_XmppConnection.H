$NetBSD: patch-nucleo_network_xmpp_XmppConnection.H,v 1.1 2012/07/09 19:06:54 joerg Exp $

--- nucleo/network/xmpp/XmppConnection.H.orig	2012-07-06 13:27:17.000000000 +0000
+++ nucleo/network/xmpp/XmppConnection.H
@@ -108,7 +108,7 @@ namespace nucleo {
     //     waitFor(-1, "stream:features", 0)
     //     waitFor(1000, "proceed", "xmlns","urn:ietf:params:xml:ns:xmpp-tls", 0)
     //     waitFor(-1, "", "id","uniq123", 0)
-    XmlParser::InBox::iterator waitFor(long milliseconds, cistring tagname, ...) ;
+    XmlParser::InBox::iterator waitFor(long milliseconds, const char *tagname, ...) ;
 
     XmlParser::InBox::iterator waitFor(long milliseconds) { return waitFor(milliseconds,"",0) ; }
     XmlParser::InBox::iterator wait(void) { return waitFor(-1,"",0) ; }
