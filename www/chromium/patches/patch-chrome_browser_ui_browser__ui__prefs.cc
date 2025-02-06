$NetBSD: patch-chrome_browser_ui_browser__ui__prefs.cc,v 1.1 2025/02/06 09:57:52 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/browser_ui_prefs.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ chrome/browser/ui/browser_ui_prefs.cc
@@ -72,7 +72,7 @@ void RegisterBrowserPrefs(PrefRegistrySi
   registry->RegisterIntegerPref(prefs::kDefaultBrowserDeclinedCount, 0);
   registry->RegisterTimePref(prefs::kDefaultBrowserFirstShownTime,
                              base::Time());
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   registry->RegisterStringPref(prefs::kEnterpriseCustomLabel, std::string());
   registry->RegisterStringPref(prefs::kEnterpriseLogoUrl, std::string());
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
@@ -182,7 +182,7 @@ void RegisterBrowserUserPrefs(user_prefs
   registry->RegisterDictionaryPref(prefs::kHttpsUpgradeFallbacks);
   registry->RegisterDictionaryPref(prefs::kHttpsUpgradeNavigations);
   registry->RegisterBooleanPref(prefs::kHttpsOnlyModeAutoEnabled, false);
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   registry->RegisterStringPref(prefs::kEnterpriseLogoUrl, std::string());
   registry->RegisterStringPref(prefs::kEnterpriseCustomLabel, std::string());
   registry->RegisterStringPref(prefs::kEnterpriseLogoUrlForProfile,
