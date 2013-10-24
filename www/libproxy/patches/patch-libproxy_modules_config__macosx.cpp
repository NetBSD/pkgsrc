$NetBSD: patch-libproxy_modules_config__macosx.cpp,v 1.1 2013/10/24 22:18:03 jperkin Exp $

Patch from upstream to fix OSX build.

--- libproxy/modules/config_macosx.cpp.orig	2012-07-05 16:50:06.000000000 +0000
+++ libproxy/modules/config_macosx.cpp
@@ -114,7 +114,7 @@ static string capitalize(string str) {
 
 class macosx_config_extension : public config_extension {
 public:
-	vector<url> get_config(const url &url) throw (runtime_error) {
+	vector<url> get_config(const url &the_url) throw (runtime_error) {
 		string tmp;
 		CFDictionaryRef proxies = SCDynamicStoreCopyProxies(NULL);
 		vector<url> response;
@@ -136,8 +136,8 @@ public:
 		}
 
 		// http:// or socks:// (TODO: gopher:// and rtsp:// ???)
-		else if ((protocol_url(proxies, toupper(url.get_scheme()), tmp)    && url::is_valid(tmp)) ||
-		    (protocol_url(proxies, capitalize(url.get_scheme()), tmp) && url::is_valid(tmp)) ||
+		else if ((protocol_url(proxies, toupper(the_url.get_scheme()), tmp)    && url::is_valid(tmp)) ||
+		    (protocol_url(proxies, capitalize(the_url.get_scheme()), tmp) && url::is_valid(tmp)) ||
 		    (protocol_url(proxies, toupper("http"), tmp)              && url::is_valid(tmp)) ||
 	            (protocol_url(proxies, toupper("socks"), tmp)             && url::is_valid(tmp))) {
 			CFRelease(proxies);
