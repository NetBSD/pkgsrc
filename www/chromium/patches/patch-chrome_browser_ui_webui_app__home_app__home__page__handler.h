$NetBSD: patch-chrome_browser_ui_webui_app__home_app__home__page__handler.h,v 1.13 2025/12/23 13:22:15 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/webui/app_home/app_home_page_handler.h.orig	2025-12-17 23:05:18.000000000 +0000
+++ chrome/browser/ui/webui/app_home/app_home_page_handler.h
@@ -23,7 +23,7 @@
 #include "mojo/public/cpp/bindings/receiver.h"
 #include "mojo/public/cpp/bindings/remote.h"
 
-static_assert(BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX));
+static_assert(BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD));
 
 class Browser;
 class ExtensionEnableFlow;
