$NetBSD: patch-chrome_browser_ui_webui_management_management__ui.cc,v 1.1 2025/02/06 09:57:55 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/webui/management/management_ui.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ chrome/browser/ui/webui/management/management_ui.cc
@@ -185,11 +185,11 @@ void ManagementUI::GetLocalizedStrings(
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
