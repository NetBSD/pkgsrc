$NetBSD: patch-src_3rdparty_chromium_chrome_browser_extensions_api_settings__private_prefs__util.cc,v 1.1 2021/08/03 21:04:34 markd Exp $

--- src/3rdparty/chromium/chrome/browser/extensions/api/settings_private/prefs_util.cc.orig	2020-07-08 21:41:46.000000000 +0000
+++ src/3rdparty/chromium/chrome/browser/extensions/api/settings_private/prefs_util.cc
@@ -163,7 +163,7 @@ const PrefsUtil::TypedPrefMap& PrefsUtil
   (*s_whitelist)[bookmarks::prefs::kShowBookmarkBar] =
       settings_api::PrefType::PREF_TYPE_BOOLEAN;
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   (*s_whitelist)[::prefs::kUseCustomChromeFrame] =
       settings_api::PrefType::PREF_TYPE_BOOLEAN;
 #endif
@@ -173,7 +173,7 @@ const PrefsUtil::TypedPrefMap& PrefsUtil
   // Appearance settings.
   (*s_whitelist)[::prefs::kCurrentThemeID] =
       settings_api::PrefType::PREF_TYPE_STRING;
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   (*s_whitelist)[::prefs::kUsesSystemTheme] =
       settings_api::PrefType::PREF_TYPE_BOOLEAN;
 #endif
