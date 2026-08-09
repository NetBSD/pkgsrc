$NetBSD: patch-chrome_browser_ui_webui_management_management__ui__handler.cc,v 1.24 2026/08/09 06:31:12 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/webui/management/management_ui_handler.cc.orig	2026-08-05 20:17:42.000000000 +0000
+++ chrome/browser/ui/webui/management/management_ui_handler.cc
@@ -74,7 +74,7 @@
 #include "ui/base/l10n/l10n_util.h"
 #include "ui/base/webui/web_ui_util.h"
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/signals/user_permission_service_factory.h"
 #include "components/device_signals/core/browser/user_permission_service.h"  // nogncheck
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
@@ -197,7 +197,7 @@ void AddThreatProtectionPermission(const
 #endif  // BUILDFLAG(ENTERPRISE_CLOUD_CONTENT_ANALYSIS)
 
 bool IsSaasReportingEnabled(content::WebUI* web_ui) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return !Profile::FromWebUI(web_ui)
               ->GetPrefs()
               ->GetList(enterprise_reporting::kSaasUsageDomainUrlsForProfile)
@@ -398,7 +398,7 @@ void ManagementUIHandler::AddBrowserRepo
     report_sources->Append(std::move(data));
   }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   auto device_signal_data = GetDeviceSignalGrantedMessage();
   if (!device_signal_data.empty()) {
     report_sources->Append(std::move(device_signal_data));
@@ -430,7 +430,7 @@ void ManagementUIHandler::AddProfileRepo
     report_sources->Append(std::move(data));
   }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   auto device_signal_data = GetDeviceSignalGrantedMessage();
   if (!device_signal_data.empty()) {
     report_sources->Append(std::move(device_signal_data));
@@ -620,7 +620,7 @@ policy::PolicyService* ManagementUIHandl
       ->policy_service();
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 device_signals::UserPermissionService*
 ManagementUIHandler::GetUserPermissionService() {
   return enterprise_signals::UserPermissionServiceFactory::GetForProfile(
