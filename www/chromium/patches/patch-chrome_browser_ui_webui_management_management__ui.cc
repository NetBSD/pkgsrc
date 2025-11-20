$NetBSD: patch-chrome_browser_ui_webui_management_management__ui.cc,v 1.10 2025/11/20 08:36:10 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/webui/management/management_ui.cc.orig	2025-11-14 20:31:45.000000000 +0000
+++ chrome/browser/ui/webui/management/management_ui.cc
@@ -183,11 +183,11 @@ void ManagementUI::GetLocalizedStrings(
        IDS_MANAGEMENT_FILE_TRANSFER_VISIBLE_DATA},
       {kManagementReportFileEvents, IDS_MANAGEMENT_REPORT_FILE_EVENTS},
 #endif  // BUILDFLAG(IS_CHROMEOS)
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       {kManagementScreenCaptureEvent, IDS_MANAGEMENT_SCREEN_CAPTURE_EVENT},
       {kManagementScreenCaptureData, IDS_MANAGEMENT_SCREEN_CAPTURE_DATA},
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       {kManagementDeviceSignalsDisclosure,
        IDS_MANAGEMENT_DEVICE_SIGNALS_DISCLOSURE},
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
