$NetBSD: patch-chrome_browser_ui_test_test__browser__ui.cc,v 1.17 2026/04/10 17:31:50 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/test/test_browser_ui.cc.orig	2026-04-06 16:25:54.000000000 +0000
+++ chrome/browser/ui/test/test_browser_ui.cc
@@ -21,7 +21,7 @@
 #include "ui/views/widget/widget.h"
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "content/public/common/content_switches.h"
 #include "ui/base/test/skia_gold_matching_algorithm.h"
 #include "ui/compositor/compositor.h"
@@ -35,7 +35,7 @@
 #endif
 
 // TODO(crbug.com/40625383) support Mac for pixel tests.
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #define SUPPORTS_PIXEL_TEST
 #endif
 
