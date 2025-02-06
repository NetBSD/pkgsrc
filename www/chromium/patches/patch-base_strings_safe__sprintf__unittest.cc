$NetBSD: patch-base_strings_safe__sprintf__unittest.cc,v 1.1 2025/02/06 09:57:42 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/strings/safe_sprintf_unittest.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ base/strings/safe_sprintf_unittest.cc
@@ -740,6 +740,7 @@ TEST(SafeSPrintfTest, EmbeddedNul) {
 #endif
 }
 
+#if !BUILDFLAG(IS_BSD)
 TEST(SafeSPrintfTest, EmitNULL) {
   char buf[40];
 #if defined(__GNUC__)
@@ -756,6 +757,7 @@ TEST(SafeSPrintfTest, EmitNULL) {
 #pragma GCC diagnostic pop
 #endif
 }
+#endif
 
 TEST(SafeSPrintfTest, PointerSize) {
   // The internal data representation is a 64bit value, independent of the
