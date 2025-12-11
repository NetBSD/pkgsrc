$NetBSD: patch-base_strings_safe__sprintf__unittest.cc,v 1.11 2025/12/11 09:13:28 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/strings/safe_sprintf_unittest.cc.orig	2025-11-19 21:40:05.000000000 +0000
+++ base/strings/safe_sprintf_unittest.cc
@@ -747,6 +747,7 @@ TEST(SafeSPrintfTest, EmbeddedNul) {
 #endif
 }
 
+#if !BUILDFLAG(IS_BSD)
 TEST(SafeSPrintfTest, EmitNULL) {
   char buf[40];
 #if defined(__GNUC__)
@@ -763,6 +764,7 @@ TEST(SafeSPrintfTest, EmitNULL) {
 #pragma GCC diagnostic pop
 #endif
 }
+#endif
 
 TEST(SafeSPrintfTest, PointerSize) {
   // The internal data representation is a 64bit value, independent of the
