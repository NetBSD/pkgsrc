$NetBSD: patch-chrome_browser_ui_browser__ui__prefs.cc,v 1.32 2026/11/08 15:38:56 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/browser_ui_prefs.cc.orig	2026-11-02 23:22:33.000000000 +0000
+++ chrome/browser/ui/browser_ui_prefs.cc
@@ -97,7 +97,7 @@ void RegisterBrowserPrefs(PrefRegistrySi
   registry->RegisterTimePref(prefs::kPinInfoBarLastShown, base::Time());
   registry->RegisterIntegerPref(prefs::kPinInfoBarTimesShown, 0);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   registry->RegisterStringPref(prefs::kEnterpriseCustomLabelForBrowser,
                                std::string());
   registry->RegisterStringPref(prefs::kEnterpriseLogoUrlForBrowser,
@@ -118,7 +118,7 @@ void RegisterBrowserUserPrefs(user_prefs
       user_prefs::PrefRegistrySyncable::SYNCABLE_PREF;
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   registry->RegisterIntegerPref(prefs::kSessionRestoreInfoBarTimesShown, 0);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
 
@@ -240,7 +240,7 @@ void RegisterBrowserUserPrefs(user_prefs
   registry->RegisterDictionaryPref(prefs::kHttpsUpgradeFallbacks);
   registry->RegisterDictionaryPref(prefs::kHttpsUpgradeNavigations);
   registry->RegisterBooleanPref(prefs::kHttpsOnlyModeAutoEnabled, false);
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   registry->RegisterStringPref(prefs::kEnterpriseLogoUrlForProfile,
                                std::string());
   registry->RegisterStringPref(prefs::kEnterpriseCustomLabelForProfile,
