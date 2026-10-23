$NetBSD: patch-chrome_browser_ui_test_test__browser__ui.cc,v 1.31 2026/10/23 15:05:20 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/test/test_browser_ui.cc.orig	2026-10-19 20:07:21.000000000 +0000
+++ chrome/browser/ui/test/test_browser_ui.cc
@@ -24,7 +24,7 @@
 #include "ui/events/test/event_generator.h"  // nogncheck
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "content/public/common/content_switches.h"
 #include "ui/base/test/skia_gold_matching_algorithm.h"
 #include "ui/compositor/compositor.h"
@@ -38,7 +38,7 @@
 #endif
 
 // TODO(crbug.com/40625383) support Mac for pixel tests.
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #define SUPPORTS_PIXEL_TEST
 #endif
 
