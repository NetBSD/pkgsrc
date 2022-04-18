$NetBSD: patch-src_3rdparty_chromium_chrome_common_pref__names.h,v 1.2 2022/04/18 11:18:18 adam Exp $

--- src/3rdparty/chromium/chrome/common/pref_names.h.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/chrome/common/pref_names.h
@@ -355,7 +355,7 @@ extern const char kHistoryMenuPromoShown
 extern const char kForceGoogleSafeSearch[];
 extern const char kForceYouTubeRestrict[];
 extern const char kAllowedDomainsForApps[];
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 extern const char kUsesSystemTheme[];
 #endif
 extern const char kCurrentThemePackFilename[];
@@ -385,7 +385,7 @@ extern const char kDefaultBrowserSetting
 #if defined(OS_MAC)
 extern const char kShowUpdatePromotionInfoBar[];
 #endif
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 extern const char kUseCustomChromeFrame[];
 #endif
 #if BUILDFLAG(ENABLE_PLUGINS)
@@ -555,7 +555,7 @@ extern const char kDownloadExtensionsToO
 extern const char kDownloadAllowedURLsForOpenByPolicy[];
 extern const char kDownloadDirUpgraded[];
 #if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || \
-    defined(OS_MAC)
+    defined(OS_MAC) || defined(OS_BSD)
 extern const char kOpenPdfDownloadInSystemReader[];
 #endif
 #if defined(OS_ANDROID)
@@ -777,7 +777,7 @@ extern const char kAllowCrossOriginAuthP
 extern const char kGloballyScopeHTTPAuthCacheEnabled[];
 extern const char kAmbientAuthenticationInPrivateModesEnabled[];
 
-#if defined(OS_LINUX) || defined(OS_MAC) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_MAC) || defined(OS_CHROMEOS) || defined(OS_BSD)
 extern const char kAuthNegotiateDelegateByKdcPolicy[];
 #endif  // defined(OS_LINUX) || defined(OS_MAC) || defined(OS_CHROMEOS)
 
@@ -1006,7 +1006,7 @@ extern const char kAutoplayWhitelist[];
 extern const char kBlockAutoplayEnabled[];
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 extern const char kAllowNativeNotifications[];
 #endif
 
