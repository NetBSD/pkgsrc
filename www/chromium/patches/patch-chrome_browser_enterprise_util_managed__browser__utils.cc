$NetBSD: patch-chrome_browser_enterprise_util_managed__browser__utils.cc,v 1.3 2025/07/25 16:17:11 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/enterprise/util/managed_browser_utils.cc.orig	2025-07-21 19:32:31.000000000 +0000
+++ chrome/browser/enterprise/util/managed_browser_utils.cc
@@ -213,7 +213,7 @@ void SetUserAcceptedAccountManagement(Pr
   // The updated consent screen also ask the user for consent to share device
   // signals.
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (accepted && base::FeatureList::IsEnabled(
                       features::kEnterpriseUpdatedProfileCreationScreen)) {
     profile->GetPrefs()->SetBoolean(
@@ -225,7 +225,7 @@ void SetUserAcceptedAccountManagement(Pr
       profile_manager->GetProfileAttributesStorage()
           .GetProfileAttributesWithPath(profile->GetPath());
   if (entry) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     SetEnterpriseProfileLabel(profile);
 #endif
     entry->SetUserAcceptedAccountManagement(accepted);
@@ -344,7 +344,7 @@ bool CanShowEnterpriseProfileUI(Profile*
 }
 
 bool CanShowEnterpriseBadgingForNTPFooter(Profile* profile) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
   auto* management_service =
       policy::ManagementServiceFactory::GetForProfile(profile);
