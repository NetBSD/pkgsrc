$NetBSD: patch-chrome_browser_themes_theme__helper.cc,v 1.31 2026/10/23 15:05:19 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/themes/theme_helper.cc.orig	2026-10-19 20:07:21.000000000 +0000
+++ chrome/browser/themes/theme_helper.cc
@@ -29,7 +29,7 @@
 #include "chrome/browser/themes/browser_theme_pack.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/linux/linux_ui.h"
 #endif
 
