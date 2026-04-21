$NetBSD: patch-chrome_browser_ui_webui_management_management__ui__handler.h,v 1.18 2026/04/21 15:21:12 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/webui/management/management_ui_handler.h.orig	2026-04-14 23:31:37.000000000 +0200
+++ chrome/browser/ui/webui/management/management_ui_handler.h
@@ -33,7 +33,7 @@ namespace enterprise_management {
 class GetUserEligiblePromotionsResponse;
 }  // namespace enterprise_management
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 namespace device_signals {
 class UserPermissionService;
 }  // namespace device_signals
@@ -90,7 +90,7 @@ class ManagementUIHandler : public conte
   base::ListValue GetManagedWebsitesInfo(Profile* profile) const;
   base::ListValue GetApplicationsInfo(Profile* profile) const;
   virtual policy::PolicyService* GetPolicyService();
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   virtual device_signals::UserPermissionService* GetUserPermissionService();
   base::DictValue GetDeviceSignalGrantedMessage();
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
