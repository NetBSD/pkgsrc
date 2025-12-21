$NetBSD: patch-src_3rdparty_chromium_chrome_browser_ui_webui_management_management__ui__constants.h,v 1.1 2025/12/21 09:38:20 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/chrome/browser/ui/webui/management/management_ui_constants.h.orig	2025-11-14 07:55:10.000000000 +0000
+++ src/3rdparty/chromium/chrome/browser/ui/webui/management/management_ui_constants.h
@@ -7,14 +7,14 @@
 
 #include "build/build_config.h"
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Constants defining the IDs for the localized strings sent to the page as
 // load time data.
 extern const char kManagementScreenCaptureEvent[];
 extern const char kManagementScreenCaptureData[];
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 extern const char kManagementDeviceSignalsDisclosure[];
 #endif  // #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
