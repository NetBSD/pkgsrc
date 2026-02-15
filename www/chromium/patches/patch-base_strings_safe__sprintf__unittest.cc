$NetBSD: patch-base_strings_safe__sprintf__unittest.cc,v 1.15 2026/02/15 09:03:55 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/strings/safe_sprintf_unittest.cc.orig	2026-02-03 22:07:10.000000000 +0000
+++ base/strings/safe_sprintf_unittest.cc
@@ -744,6 +744,7 @@ TEST(SafeSPrintfTest, EmbeddedNul) {
 #endif
 }
 
+#if !BUILDFLAG(IS_BSD)
 TEST(SafeSPrintfTest, EmitNULL) {
   char buf[40];
 #if defined(__GNUC__)
@@ -760,6 +761,7 @@ TEST(SafeSPrintfTest, EmitNULL) {
 #pragma GCC diagnostic pop
 #endif
 }
+#endif
 
 TEST(SafeSPrintfTest, PointerSize) {
   // The internal data representation is a 64bit value, independent of the
