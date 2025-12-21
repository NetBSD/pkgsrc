$NetBSD: patch-src_3rdparty_chromium_ui_color_system__theme.h,v 1.1 2025/12/21 09:38:47 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/ui/color/system_theme.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/ui/color/system_theme.h
@@ -15,7 +15,7 @@ namespace ui {
 enum class SystemTheme {
   // Classic theme, used in the default or users' chosen theme.
   kDefault = 0,
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   kGtk = 1,
   kQt = 2,
   kMaxValue = kQt,
