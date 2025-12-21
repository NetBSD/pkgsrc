$NetBSD: patch-src_3rdparty_chromium_chrome_common_webui__url__constants.h,v 1.1 2025/12/21 09:38:21 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/chrome/common/webui_url_constants.h.orig	2025-11-14 07:55:10.000000000 +0000
+++ src/3rdparty/chromium/chrome/common/webui_url_constants.h
@@ -511,18 +511,18 @@ inline constexpr char kChromeUIOsUrlAppU
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 inline constexpr char kChromeUIConnectorsInternalsHost[] =
     "connectors-internals";
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 inline constexpr char kChromeUIDiscardsHost[] = "discards";
 inline constexpr char kChromeUIDiscardsURL[] = "chrome://discards/";
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 inline constexpr char kChromeUIWebAppSettingsHost[] = "app-settings";
 inline constexpr char kChromeUIWebAppSettingsURL[] = "chrome://app-settings/";
 inline constexpr char kChromeUIWhatsNewHost[] = "whats-new";
@@ -534,11 +534,11 @@ inline constexpr char kChromeUILinuxProx
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 inline constexpr char kChromeUISandboxHost[] = "sandbox";
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 inline constexpr char kChromeUIBrowserSwitchHost[] = "browser-switch";
 inline constexpr char kChromeUIBrowserSwitchURL[] = "chrome://browser-switch/";
 inline constexpr char kChromeUIIntroDefaultBrowserSubPage[] = "default-browser";
@@ -560,7 +560,7 @@ inline constexpr char kChromeUIProfilePi
 inline constexpr char kChromeUIProfilePickerUrl[] = "chrome://profile-picker/";
 #endif
 
-#if ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && \
+#if ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) && \
      defined(TOOLKIT_VIEWS)) ||                         \
     defined(USE_AURA)
 inline constexpr char kChromeUITabModalConfirmDialogHost[] =
