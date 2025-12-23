$NetBSD: patch-chrome_browser_themes_theme__helper.cc,v 1.13 2025/12/23 13:22:14 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/themes/theme_helper.cc.orig	2025-12-17 23:05:18.000000000 +0000
+++ chrome/browser/themes/theme_helper.cc
@@ -16,7 +16,7 @@
 #include "ui/gfx/image/image.h"
 #include "ui/native_theme/native_theme.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/linux/linux_ui.h"
 #endif
 
