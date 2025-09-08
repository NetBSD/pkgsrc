$NetBSD: patch-chrome_browser_enterprise_browser__management_browser__management__service.cc,v 1.4 2025/09/08 13:24:18 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/enterprise/browser_management/browser_management_service.cc.orig	2025-08-29 18:50:09.000000000 +0000
+++ chrome/browser/enterprise/browser_management/browser_management_service.cc
@@ -50,7 +50,7 @@ GetManagementStatusProviders(Profile* pr
 
 BrowserManagementService::BrowserManagementService(Profile* profile)
     : ManagementService(GetManagementStatusProviders(profile)) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   base::SequencedTaskRunner::GetCurrentDefault()->PostTask(
       FROM_HERE,
       base::BindOnce(&BrowserManagementService::UpdateManagementIconForProfile,
@@ -74,7 +74,7 @@ BrowserManagementService::BrowserManagem
 }
 
 ui::ImageModel* BrowserManagementService::GetManagementIconForProfile() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return management_icon_for_profile_.IsEmpty() ? nullptr
                                                 : &management_icon_for_profile_;
 #else
@@ -83,7 +83,7 @@ ui::ImageModel* BrowserManagementService
 }
 
 gfx::Image* BrowserManagementService::GetManagementIconForBrowser() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return management_icon_for_browser_.IsEmpty() ? nullptr
                                                 : &management_icon_for_browser_;
 #else
@@ -96,7 +96,7 @@ void BrowserManagementService::TriggerPo
   OnPolicyStatusChanged();
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void BrowserManagementService::SetBrowserManagementIconForTesting(
     const gfx::Image& management_icon) {
   CHECK_IS_TEST();
@@ -183,7 +183,7 @@ void BrowserManagementService::SetManage
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
 void BrowserManagementService::OnPolicyStatusChanged() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   NotifyEnterpriseLabelUpdated();
 #endif
 }
