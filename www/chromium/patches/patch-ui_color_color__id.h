$NetBSD: patch-ui_color_color__id.h,v 1.19 2026/05/10 15:30:07 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/color/color_id.h.orig	2026-04-28 23:05:57.000000000 +0200
+++ ui/color/color_id.h
@@ -662,7 +662,7 @@
   E_CPONLY(kColorCrosSysPositive) \
   E_CPONLY(kColorCrosSysComplementVariant) \
   E_CPONLY(kColorCrosSysInputFieldOnBase)
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #define PLATFORM_SPECIFIC_COLOR_IDS \
   E_CPONLY(kColorNativeBoxFrameBorder)\
   E_CPONLY(kColorNativeHeaderButtonBorderActive) \
