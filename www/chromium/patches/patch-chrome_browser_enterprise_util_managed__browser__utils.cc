$NetBSD: patch-chrome_browser_enterprise_util_managed__browser__utils.cc,v 1.32 2026/11/19 19:45:53 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/enterprise/util/managed_browser_utils.cc.orig	2026-11-11 21:01:38.000000000 +0000
+++ chrome/browser/enterprise/util/managed_browser_utils.cc
@@ -301,7 +301,7 @@ void SetUserAcceptedAccountManagement(Pr
   // The updated consent screen also ask the user for consent to share device
   // signals.
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   profile->GetPrefs()->SetBoolean(
       device_signals::prefs::kDeviceSignalsPermanentConsentReceived, accepted);
 #endif
@@ -310,7 +310,7 @@ void SetUserAcceptedAccountManagement(Pr
       profile_manager->GetProfileAttributesStorage()
           .GetProfileAttributesWithPath(profile->GetPath());
   if (entry) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     SetEnterpriseProfileLabel(profile);
 #endif
     entry->SetUserAcceptedAccountManagement(accepted);
@@ -396,7 +396,7 @@ bool CanShowEnterpriseProfileUI(Profile*
 }
 
 bool CanShowEnterpriseBadgingForNTPFooter(Profile* profile) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   BrowserManagementNoticeState management_notice_state =
       GetManagementNoticeStateForNTPFooter(profile);
   switch (management_notice_state) {
@@ -414,7 +414,7 @@ bool CanShowEnterpriseBadgingForNTPFoote
 
 BrowserManagementNoticeState GetManagementNoticeStateForNTPFooter(
     Profile* profile) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   auto* management_service =
       policy::ManagementServiceFactory::GetForProfile(profile);
   if (!management_service->IsBrowserManaged() ||
