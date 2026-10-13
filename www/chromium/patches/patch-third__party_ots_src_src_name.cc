$NetBSD: patch-third__party_ots_src_src_name.cc,v 1.2 2026/10/13 13:16:49 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/ots/src/src/name.cc.orig	2026-10-06 00:06:58.000000000 +0000
+++ third_party/ots/src/src/name.cc
@@ -16,7 +16,7 @@ namespace {
 // We disallow characters outside the URI spec "unreserved characters"
 // set; any chars outside this set will be replaced by underscore.
 bool AllowedInPsName(char c) {
-  return isalnum(c) || std::strchr("-._~", c);
+  return isalnum(static_cast<unsigned char>(c)) || std::strchr("-._~", c);
 }
 
 bool SanitizePsNameAscii(std::string& name) {
