$NetBSD: patch-base_strings_safe__sprintf__unittest.cc,v 1.3 2025/07/07 09:23:25 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/strings/safe_sprintf_unittest.cc.orig	2025-06-30 06:54:11.000000000 +0000
+++ base/strings/safe_sprintf_unittest.cc
@@ -746,6 +746,7 @@ TEST(SafeSPrintfTest, EmbeddedNul) {
 #endif
 }
 
+#if !BUILDFLAG(IS_BSD)
 TEST(SafeSPrintfTest, EmitNULL) {
   char buf[40];
 #if defined(__GNUC__)
@@ -762,6 +763,7 @@ TEST(SafeSPrintfTest, EmitNULL) {
 #pragma GCC diagnostic pop
 #endif
 }
+#endif
 
 TEST(SafeSPrintfTest, PointerSize) {
   // The internal data representation is a 64bit value, independent of the
