$NetBSD: patch-third__party_ots_src_src_name.cc,v 1.1 2026/10/02 11:43:37 kikadf Exp $

* Fix ctype abuse

--- third_party/ots/src/src/name.cc.orig	2026-10-02 11:13:42.664121307 +0000
+++ third_party/ots/src/src/name.cc
@@ -16,7 +16,7 @@ namespace {
 // We disallow characters outside the URI spec "unreserved characters"
 // set; any chars outside this set will be replaced by underscore.
 bool AllowedInPsName(char c) {
-  return isalnum(c) || std::strchr("-._~", c);
+  return isalnum(static_cast<unsigned char>(c)) || std::strchr("-._~", c);
 }
 
 bool SanitizePsNameAscii(std::string& name) {
