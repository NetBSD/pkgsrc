$NetBSD: patch-src_3rdparty_chromium_chrome_browser_ui_webui_app__home_app__home__page__handler.h,v 1.1 2025/12/21 09:38:19 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/chrome/browser/ui/webui/app_home/app_home_page_handler.h.orig	2025-09-25 11:10:42.000000000 +0000
+++ src/3rdparty/chromium/chrome/browser/ui/webui/app_home/app_home_page_handler.h
@@ -24,7 +24,7 @@
 #include "mojo/public/cpp/bindings/receiver.h"
 #include "mojo/public/cpp/bindings/remote.h"
 
-static_assert(BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX));
+static_assert(BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD));
 
 class ExtensionEnableFlow;
 
