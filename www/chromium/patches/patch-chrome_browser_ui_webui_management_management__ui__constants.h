$NetBSD: patch-chrome_browser_ui_webui_management_management__ui__constants.h,v 1.19 2026/05/10 15:29:53 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/webui/management/management_ui_constants.h.orig	2026-04-28 23:05:57.000000000 +0200
+++ chrome/browser/ui/webui/management/management_ui_constants.h
@@ -9,14 +9,14 @@
 #include "build/build_config.h"
 #include "extensions/buildflags/buildflags.h"
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Constants defining the IDs for the localized strings sent to the page as
 // load time data.
 extern const char kManagementScreenCaptureEvent[];
 extern const char kManagementScreenCaptureData[];
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || (BUILDFLAG(IS_ANDROID) && BUILDFLAG(ENABLE_EXTENSIONS_CORE))
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || (BUILDFLAG(IS_ANDROID) && BUILDFLAG(ENABLE_EXTENSIONS_CORE)) || BUILDFLAG(IS_BSD)
 extern const char kManagementDeviceSignalsDisclosure[];
 #endif  // #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || (BUILDFLAG(IS_ANDROID) && BUILDFLAG(ENABLE_EXTENSIONS_CORE))
 
