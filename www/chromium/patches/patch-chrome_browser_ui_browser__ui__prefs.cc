$NetBSD: patch-chrome_browser_ui_browser__ui__prefs.cc,v 1.8 2025/10/16 19:43:23 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/browser_ui_prefs.cc.orig	2025-10-13 21:41:26.000000000 +0000
+++ chrome/browser/ui/browser_ui_prefs.cc
@@ -82,7 +82,7 @@ void RegisterBrowserPrefs(PrefRegistrySi
   registry->RegisterTimePref(prefs::kPinInfoBarLastShown, base::Time());
   registry->RegisterIntegerPref(prefs::kPinInfoBarTimesShown, 0);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   registry->RegisterStringPref(prefs::kEnterpriseCustomLabelForBrowser,
                                std::string());
   registry->RegisterStringPref(prefs::kEnterpriseLogoUrlForBrowser,
@@ -212,7 +212,7 @@ void RegisterBrowserUserPrefs(user_prefs
   registry->RegisterDictionaryPref(prefs::kHttpsUpgradeFallbacks);
   registry->RegisterDictionaryPref(prefs::kHttpsUpgradeNavigations);
   registry->RegisterBooleanPref(prefs::kHttpsOnlyModeAutoEnabled, false);
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   registry->RegisterStringPref(prefs::kEnterpriseLogoUrlForProfile,
                                std::string());
   registry->RegisterStringPref(prefs::kEnterpriseCustomLabelForProfile,
