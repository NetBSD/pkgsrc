$NetBSD: patch-src_3rdparty_chromium_chrome_browser_extensions_api_settings__private_prefs__util.cc,v 1.1 2025/12/21 09:38:18 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/chrome/browser/extensions/api/settings_private/prefs_util.cc.orig	2025-05-29 01:27:28.000000000 +0000
+++ src/3rdparty/chromium/chrome/browser/extensions/api/settings_private/prefs_util.cc
@@ -211,7 +211,7 @@ const PrefsUtil::TypedPrefMap& PrefsUtil
   (*s_allowlist)[tab_groups::prefs::kAutoPinNewTabGroups] =
       settings_api::PrefType::kBoolean;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   (*s_allowlist)[::prefs::kUseCustomChromeFrame] =
       settings_api::PrefType::kBoolean;
 #endif
@@ -223,7 +223,7 @@ const PrefsUtil::TypedPrefMap& PrefsUtil
   (*s_allowlist)[::prefs::kCurrentThemeID] = settings_api::PrefType::kString;
   (*s_allowlist)[::prefs::kPinnedActions] = settings_api::PrefType::kList;
   (*s_allowlist)[::prefs::kPolicyThemeColor] = settings_api::PrefType::kNumber;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   (*s_allowlist)[::prefs::kSystemTheme] = settings_api::PrefType::kNumber;
 #endif
   (*s_allowlist)[::prefs::kHomePage] = settings_api::PrefType::kUrl;
