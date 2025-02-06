$NetBSD: patch-ui_base_test_skia__gold__pixel__diff.cc,v 1.1 2025/02/06 09:58:31 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/base/test/skia_gold_pixel_diff.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ ui/base/test/skia_gold_pixel_diff.cc
@@ -115,7 +115,7 @@ const char* GetPlatformName() {
   return "macOS";
 // TODO(crbug.com/40118868): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return "linux";
 #elif BUILDFLAG(IS_CHROMEOS_LACROS)
   return "lacros";
