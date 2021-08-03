$NetBSD: patch-src_3rdparty_chromium_chrome_common_pref__names.h,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/chrome/common/pref_names.h.orig	2020-11-07 01:22:36.000000000 +0000
+++ src/3rdparty/chromium/chrome/common/pref_names.h
@@ -346,7 +346,7 @@ extern const char kHistoryMenuPromoShown
 extern const char kForceGoogleSafeSearch[];
 extern const char kForceYouTubeRestrict[];
 extern const char kAllowedDomainsForApps[];
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 extern const char kUsesSystemTheme[];
 #endif
 extern const char kCurrentThemePackFilename[];
@@ -377,7 +377,7 @@ extern const char kDefaultBrowserSetting
 #if defined(OS_MACOSX)
 extern const char kShowUpdatePromotionInfoBar[];
 #endif
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 extern const char kUseCustomChromeFrame[];
 #endif
 #if BUILDFLAG(ENABLE_PLUGINS)
@@ -545,7 +545,7 @@ extern const char kAppWindowPlacement[];
 extern const char kDownloadDefaultDirectory[];
 extern const char kDownloadExtensionsToOpen[];
 extern const char kDownloadDirUpgraded[];
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
 extern const char kOpenPdfDownloadInSystemReader[];
 #endif
 #if defined(OS_ANDROID)
@@ -758,7 +758,7 @@ extern const char kAllowCrossOriginAuthP
 extern const char kGloballyScopeHTTPAuthCacheEnabled[];
 extern const char kAmbientAuthenticationInPrivateModesEnabled[];
 
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 extern const char kAuthNegotiateDelegateByKdcPolicy[];
 #endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_CHROMEOS)
 
@@ -991,7 +991,7 @@ extern const char kAutoplayWhitelist[];
 extern const char kBlockAutoplayEnabled[];
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 extern const char kAllowNativeNotifications[];
 #endif
 
