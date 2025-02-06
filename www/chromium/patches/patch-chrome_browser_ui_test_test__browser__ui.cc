$NetBSD: patch-chrome_browser_ui_test_test__browser__ui.cc,v 1.1 2025/02/06 09:57:53 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/test/test_browser_ui.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ chrome/browser/ui/test/test_browser_ui.cc
@@ -22,7 +22,7 @@
 
 // TODO(crbug.com/40118868): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD) || \
     (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
 #include "content/public/common/content_switches.h"
 #include "ui/base/test/skia_gold_matching_algorithm.h"
@@ -39,7 +39,7 @@
 // TODO(crbug.com/40625383) support Mac for pixel tests.
 // TODO(crbug.com/40118868): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_WIN) || (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+#if BUILDFLAG(IS_WIN) || (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD))
 #define SUPPORTS_PIXEL_TEST
 #endif
 
