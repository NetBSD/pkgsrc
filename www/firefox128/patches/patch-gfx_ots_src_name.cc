$NetBSD: patch-gfx_ots_src_name.cc,v 1.1 2025/09/11 14:42:22 leot Exp $

Fix ctype(3) abuses.

--- gfx/ots/src/name.cc.orig	2025-09-11 14:28:47.940108735 +0000
+++ gfx/ots/src/name.cc
@@ -16,7 +16,7 @@ namespace {
 // We disallow characters outside the URI spec "unreserved characters"
 // set; any chars outside this set will be replaced by underscore.
 bool AllowedInPsName(char c) {
-  return isalnum(c) || std::strchr("-._~", c);
+  return isalnum((unsigned char)c) || std::strchr("-._~", c);
 }
 
 bool SanitizePsNameAscii(std::string& name) {
