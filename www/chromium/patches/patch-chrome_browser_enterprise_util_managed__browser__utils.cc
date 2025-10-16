$NetBSD: patch-chrome_browser_enterprise_util_managed__browser__utils.cc,v 1.7 2025/10/16 19:43:21 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/enterprise/util/managed_browser_utils.cc.orig	2025-10-13 21:41:26.000000000 +0000
+++ chrome/browser/enterprise/util/managed_browser_utils.cc
@@ -300,7 +300,7 @@ void SetUserAcceptedAccountManagement(Pr
   // The updated consent screen also ask the user for consent to share device
   // signals.
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   profile->GetPrefs()->SetBoolean(
       device_signals::prefs::kDeviceSignalsPermanentConsentReceived, accepted);
 #endif
@@ -309,7 +309,7 @@ void SetUserAcceptedAccountManagement(Pr
       profile_manager->GetProfileAttributesStorage()
           .GetProfileAttributesWithPath(profile->GetPath());
   if (entry) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     SetEnterpriseProfileLabel(profile);
 #endif
     entry->SetUserAcceptedAccountManagement(accepted);
@@ -428,7 +428,7 @@ bool CanShowEnterpriseProfileUI(Profile*
 }
 
 bool CanShowEnterpriseBadgingForNTPFooter(Profile* profile) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   BrowserManagementNoticeState management_notice_state =
       GetManagementNoticeStateForNTPFooter(profile);
   switch (management_notice_state) {
@@ -446,7 +446,7 @@ bool CanShowEnterpriseBadgingForNTPFoote
 
 BrowserManagementNoticeState GetManagementNoticeStateForNTPFooter(
     Profile* profile) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!policy::ManagementServiceFactory::GetForProfile(profile)
            ->IsBrowserManaged() ||
       !g_browser_process->local_state()->GetBoolean(
