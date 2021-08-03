$NetBSD: patch-src_3rdparty_chromium_chrome_common_pref__names.cc,v 1.1 2021/08/03 21:04:34 markd Exp $

--- src/3rdparty/chromium/chrome/common/pref_names.cc.orig	2020-07-08 21:41:47.000000000 +0000
+++ src/3rdparty/chromium/chrome/common/pref_names.cc
@@ -1081,7 +1081,7 @@ const char kForceYouTubeRestrict[] = "se
 // only using an account that belongs to one of the domains from this pref.
 const char kAllowedDomainsForApps[] = "settings.allowed_domains_for_apps";
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 // Linux specific preference on whether we should match the system theme.
 const char kUsesSystemTheme[] = "extensions.theme.use_system";
 #endif
@@ -1224,7 +1224,7 @@ const char kShowUpdatePromotionInfoBar[]
     "browser.show_update_promotion_info_bar";
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 // Boolean that is false if we should show window manager decorations.  If
 // true, we draw a custom chrome frame (thicker title bar and blue border).
 const char kUseCustomChromeFrame[] = "browser.custom_chrome_frame";
@@ -1667,7 +1667,7 @@ const char kDownloadDefaultDirectory[] =
 // upgrade a unsafe location to a safe location.
 const char kDownloadDirUpgraded[] = "download.directory_upgrade";
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_BSD)
 const char kOpenPdfDownloadInSystemReader[] =
     "download.open_pdf_in_system_reader";
 #endif
@@ -1982,7 +1982,7 @@ const char kGloballyScopeHTTPAuthCacheEn
 const char kAmbientAuthenticationInPrivateModesEnabled[] =
     "auth.ambient_auth_in_private_modes";
 
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 // Boolean that specifies whether OK-AS-DELEGATE flag from KDC is respected
 // along with kAuthNegotiateDelegateWhitelist.
 const char kAuthNegotiateDelegateByKdcPolicy[] =
@@ -2908,7 +2908,7 @@ const char kAutoplayWhitelist[] = "media
 const char kBlockAutoplayEnabled[] = "media.block_autoplay";
 #endif  // !defined(OS_ANDROID)
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 // Boolean that indicates if native notifications are allowed to be used in
 // place of Chrome notifications.
 const char kAllowNativeNotifications[] = "native_notifications.allowed";
