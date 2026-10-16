$NetBSD: patch-third__party_ots_src_src_name.cc,v 1.3 2026/10/16 15:31:00 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/ots/src/src/name.cc.orig	2026-10-14 21:09:54.000000000 +0000
+++ third_party/ots/src/src/name.cc
@@ -16,7 +16,7 @@ namespace {
 // We disallow characters outside the URI spec "unreserved characters"
 // set; any chars outside this set will be replaced by underscore.
 bool AllowedInPsName(char c) {
-  return isalnum(c) || std::strchr("-._~", c);
+  return isalnum(static_cast<unsigned char>(c)) || std::strchr("-._~", c);
 }
 
 bool SanitizePsNameAscii(std::string& name) {
