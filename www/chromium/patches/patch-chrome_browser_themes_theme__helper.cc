$NetBSD: patch-chrome_browser_themes_theme__helper.cc,v 1.21 2026/06/08 13:12:33 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/themes/theme_helper.cc.orig	2026-05-28 23:24:11.000000000 +0000
+++ chrome/browser/themes/theme_helper.cc
@@ -15,7 +15,7 @@
 #include "ui/gfx/image/image.h"
 #include "ui/native_theme/native_theme.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/linux/linux_ui.h"
 #endif
 
