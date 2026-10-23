$NetBSD: patch-chrome_browser_ui_webui_management_management__ui__handler.cc,v 1.31 2026/10/23 15:05:22 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/webui/management/management_ui_handler.cc.orig	2026-10-19 20:07:21.000000000 +0000
+++ chrome/browser/ui/webui/management/management_ui_handler.cc
@@ -82,7 +82,7 @@
 #include "chrome/browser/ui/managed_ui.h"  // nogncheck crbug.com/40147906
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/signals/user_permission_service_factory.h"
 #include "components/device_signals/core/browser/user_permission_service.h"  // nogncheck
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
@@ -206,7 +206,7 @@ void AddThreatProtectionPermission(const
 }
 
 bool IsSaasReportingEnabled(content::WebUI* web_ui) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return !Profile::FromWebUI(web_ui)
               ->GetPrefs()
               ->GetList(enterprise_reporting::kSaasUsageDomainUrlsForProfile)
@@ -410,7 +410,7 @@ void ManagementUIHandler::AddBrowserRepo
     report_sources->Append(std::move(data));
   }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   auto device_signal_data = GetDeviceSignalGrantedMessage();
   if (!device_signal_data.empty()) {
     report_sources->Append(std::move(device_signal_data));
@@ -445,7 +445,7 @@ void ManagementUIHandler::AddProfileRepo
     report_sources->Append(std::move(data));
   }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   auto device_signal_data = GetDeviceSignalGrantedMessage();
   if (!device_signal_data.empty()) {
     report_sources->Append(std::move(device_signal_data));
@@ -637,7 +637,7 @@ policy::PolicyService* ManagementUIHandl
       ->policy_service();
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 device_signals::UserPermissionService*
 ManagementUIHandler::GetUserPermissionService() {
   return enterprise_signals::UserPermissionServiceFactory::GetForProfile(
