$NetBSD: patch-chrome_common_pref__names.h,v 1.18 2026/04/21 15:21:12 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/common/pref_names.h.orig	2026-04-14 23:31:37.000000000 +0200
+++ chrome/common/pref_names.h
@@ -1271,7 +1271,7 @@ inline constexpr char kGeminiSettings[] 
 inline constexpr char kAllowedDomainsForApps[] =
     "settings.allowed_domains_for_apps";
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Linux specific preference on whether we should match the system theme.
 inline constexpr char kSystemTheme[] = "extensions.theme.system_theme";
 #endif
@@ -1440,7 +1440,7 @@ inline constexpr char kShowUpdatePromoti
     "browser.show_update_promotion_info_bar";
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Boolean that is false if we should show window manager decorations.  If
 // true, we draw a custom chrome frame (thicker title bar and blue border).
 inline constexpr char kUseCustomChromeFrame[] = "browser.custom_chrome_frame";
@@ -2012,7 +2012,7 @@ inline constexpr char kPinInfoBarTimesSh
     "browser.pin_infobar_times_shown";
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 // How many times the session restore infobar has been shown.
 inline constexpr char kSessionRestoreInfoBarTimesShown[] =
@@ -2059,7 +2059,7 @@ inline constexpr char kDownloadDefaultDi
 inline constexpr char kDownloadDirUpgraded[] = "download.directory_upgrade";
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 inline constexpr char kOpenPdfDownloadInSystemReader[] =
     "download.open_pdf_in_system_reader";
 #endif
@@ -2519,7 +2519,7 @@ inline constexpr char kMediaStorageIdSal
 inline constexpr char kMediaCdmOriginData[] = "media.cdm.origin_data";
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // A boolean pref to determine whether or not the network service is running
 // sandboxed.
 inline constexpr char kNetworkServiceSandboxEnabled[] =
@@ -2533,7 +2533,7 @@ inline constexpr char kNetworkServiceSan
 inline constexpr char kNetworkServiceFailedLaunchMajorVersion[] =
     "net.network_service_failed_launch_major_version";
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Records whether the user has seen an HTTP auth "negotiate" header.
 inline constexpr char kReceivedHttpAuthNegotiateHeader[] =
     "net.received_http_auth_negotiate_headers";
@@ -2630,7 +2630,7 @@ inline constexpr char kIsolatedWebAppUse
 inline constexpr char kIsolatedWebAppPendingInitializationCount[] =
     "profile.isolated_web_app.install.pending_initialization_count";
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Boolean that specifies whether OK-AS-DELEGATE flag from KDC is respected
 // along with kAuthNegotiateDelegateAllowlist.
 inline constexpr char kAuthNegotiateDelegateByKdcPolicy[] =
@@ -3059,7 +3059,7 @@ inline constexpr char kDeviceAllowEnterp
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 // Defines administrator-set availability of Chrome for Testing.
 inline constexpr char kChromeForTestingAllowed[] = "chrome_for_testing.allowed";
 #endif
@@ -3539,7 +3539,7 @@ inline constexpr char kScreenCaptureWith
 inline constexpr char kSandboxExternalProtocolBlocked[] =
     "profile.sandbox_external_protocol_blocked";
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Boolean that indicates if system notifications are allowed to be used in
 // place of Chrome notifications.
 inline constexpr char kAllowSystemNotifications[] =
@@ -3732,7 +3732,7 @@ inline constexpr char kLensDesktopNTPSea
     "policy.lens_desktop_ntp_search_enabled";
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 // A dict mapping the edition name with the major version it was shown.
 inline constexpr char kWhatsNewEditionUsed[] = "browser.whats_new.edition_used";
 // A list containing the features of each module in order of when they
@@ -3829,7 +3829,7 @@ inline constexpr char kPrintingOAuth2Aut
     "printing.oauth2_authorization_servers";
 #endif
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // If this exists and is true, Chrome may run system DNS resolution out of the
 // network process. If false, Chrome will run system DNS resolution in the
 // network process. If non-existent, Chrome will decide where to run system DNS
