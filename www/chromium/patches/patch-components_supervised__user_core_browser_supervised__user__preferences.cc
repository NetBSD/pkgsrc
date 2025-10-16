$NetBSD: patch-components_supervised__user_core_browser_supervised__user__preferences.cc,v 1.8 2025/10/16 19:43:27 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/supervised_user/core/browser/supervised_user_preferences.cc.orig	2025-10-13 21:41:26.000000000 +0000
+++ components/supervised_user/core/browser/supervised_user_preferences.cc
@@ -149,7 +149,7 @@ void RegisterProfilePrefs(PrefRegistrySi
   registry->RegisterBooleanPref(prefs::kChildAccountStatusKnown, false);
   registry->RegisterStringPref(prefs::kFamilyLinkUserMemberRole, std::string());
 #if BUILDFLAG(ENABLE_EXTENSIONS) && \
-    (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX))
+    (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
   registry->RegisterIntegerPref(
       prefs::kLocallyParentApprovedExtensionsMigrationState,
       static_cast<int>(
