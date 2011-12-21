$NetBSD: patch-plugin_icedteanp_IcedTeaNPPlugin.cc,v 1.2 2011/12/21 13:09:31 wiz Exp $

Fix build with gcc-4.5.

--- plugin/icedteanp/IcedTeaNPPlugin.cc.orig	2011-08-17 16:01:19.000000000 +0000
+++ plugin/icedteanp/IcedTeaNPPlugin.cc
@@ -2262,7 +2262,7 @@ NP_Initialize (NPNetscapeFuncs* browserT
 
 // Returns a string describing the MIME type that this plugin
 // handles.
-char*
+const char*
 NP_GetMIMEDescription ()
 {
   PLUGIN_DEBUG ("NP_GetMIMEDescription\n");
