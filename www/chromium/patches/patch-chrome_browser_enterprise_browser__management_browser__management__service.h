$NetBSD: patch-chrome_browser_enterprise_browser__management_browser__management__service.h,v 1.12 2026/01/19 16:14:08 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/enterprise/browser_management/browser_management_service.h.orig	2026-01-07 00:50:30.000000000 +0000
+++ chrome/browser/enterprise/browser_management/browser_management_service.h
@@ -41,7 +41,7 @@ class BrowserManagementService : public 
 
   void TriggerPolicyStatusChangedForTesting() override;
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void SetBrowserManagementIconForTesting(
       const gfx::Image& management_icon) override;
 #endif
@@ -50,7 +50,7 @@ class BrowserManagementService : public 
   // PolicyStatusProvider::Observer:
   void OnPolicyStatusChanged() override;
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Starts listening to changes to policies that affect the enterprise label
   // and pill.
   void StartListeningToPrefChanges(Profile* profile);
