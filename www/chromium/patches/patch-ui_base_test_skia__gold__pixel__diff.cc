$NetBSD: patch-ui_base_test_skia__gold__pixel__diff.cc,v 1.25 2026/09/02 13:13:38 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/base/test/skia_gold_pixel_diff.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ ui/base/test/skia_gold_pixel_diff.cc
@@ -116,7 +116,7 @@ const char* GetPlatformName() {
   return "windows";
 #elif BUILDFLAG(IS_APPLE)
   return "macOS";
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return "linux";
 #elif BUILDFLAG(IS_CHROMEOS)
   return "ash";
