$NetBSD: patch-gfx_ots_src_name.cc,v 1.1 2025/07/26 14:12:54 ryoon Exp $

--- gfx/ots/src/name.cc.orig	2025-07-26 13:25:22.747360576 +0000
+++ gfx/ots/src/name.cc
@@ -16,7 +16,7 @@ namespace {
 // We disallow characters outside the URI spec "unreserved characters"
 // set; any chars outside this set will be replaced by underscore.
 bool AllowedInPsName(char c) {
-  return isalnum(c) || std::strchr("-._~", c);
+  return isalnum((unsigned char)c) || std::strchr("-._~", c);
 }
 
 bool SanitizePsNameAscii(std::string& name) {
