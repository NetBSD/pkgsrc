$NetBSD: patch-chrome_browser_ui_webui_management_management__ui__handler.h,v 1.1 2025/02/06 09:57:55 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/webui/management/management_ui_handler.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ chrome/browser/ui/webui/management/management_ui_handler.h
@@ -31,7 +31,7 @@ namespace policy {
 class PolicyService;
 }  // namespace policy
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 namespace device_signals {
 class UserPermissionService;
 }  // namespace device_signals
@@ -72,7 +72,7 @@ class ManagementUIHandler : public conte
   base::Value::List GetManagedWebsitesInfo(Profile* profile) const;
   base::Value::List GetApplicationsInfo(Profile* profile) const;
   virtual policy::PolicyService* GetPolicyService();
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   virtual device_signals::UserPermissionService* GetUserPermissionService();
   base::Value::Dict GetDeviceSignalGrantedMessage();
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
