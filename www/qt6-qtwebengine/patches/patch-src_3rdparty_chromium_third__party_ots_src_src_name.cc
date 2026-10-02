$NetBSD: patch-src_3rdparty_chromium_third__party_ots_src_src_name.cc,v 1.1 2026/10/02 13:08:36 kikadf Exp $

* Fix ctype abuse

--- src/3rdparty/chromium/third_party/ots/src/src/name.cc.orig	2026-10-02 12:57:12.214658841 +0000
+++ src/3rdparty/chromium/third_party/ots/src/src/name.cc
@@ -16,7 +16,7 @@ namespace {
 // We disallow characters outside the URI spec "unreserved characters"
 // set; any chars outside this set will be replaced by underscore.
 bool AllowedInPsName(char c) {
-  return isalnum(c) || std::strchr("-._~", c);
+  return isalnum(static_cast<unsigned char>(c)) || std::strchr("-._~", c);
 }
 
 bool SanitizePsNameAscii(std::string& name) {
