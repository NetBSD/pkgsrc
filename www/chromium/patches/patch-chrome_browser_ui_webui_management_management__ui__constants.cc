$NetBSD: patch-chrome_browser_ui_webui_management_management__ui__constants.cc,v 1.19 2026/05/10 15:29:53 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/webui/management/management_ui_constants.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ chrome/browser/ui/webui/management/management_ui_constants.cc
@@ -93,13 +93,13 @@ const char kProfileReportingExtension[] 
 const char kProfileReportingPolicy[] = "profileReportingPolicy";
 const char kProfileReportingLearnMore[] = "profileReportingLearnMore";
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const char kManagementScreenCaptureEvent[] = "managementScreenCaptureEvent";
 const char kManagementScreenCaptureData[] = "managementScreenCaptureData";
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    (BUILDFLAG(IS_ANDROID) && BUILDFLAG(ENABLE_EXTENSIONS_CORE))
+    (BUILDFLAG(IS_ANDROID) && BUILDFLAG(ENABLE_EXTENSIONS_CORE)) || BUILDFLAG(IS_BSD)
 const char kManagementDeviceSignalsDisclosure[] =
     "managementDeviceSignalsDisclosure";
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
