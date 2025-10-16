$NetBSD: patch-chrome_common_webui__url__constants.h,v 1.8 2025/10/16 19:43:25 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/common/webui_url_constants.h.orig	2025-10-13 21:41:26.000000000 +0000
+++ chrome/common/webui_url_constants.h
@@ -554,12 +554,12 @@ inline constexpr char kChromeUIOsUrlAppU
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_DESKTOP_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_DESKTOP_ANDROID) || BUILDFLAG(IS_BSD)
 inline constexpr char kChromeUIDiscardsHost[] = "discards";
 inline constexpr char kChromeUIDiscardsURL[] = "chrome://discards/";
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 inline constexpr char kChromeUIWebAppSettingsHost[] = "app-settings";
 inline constexpr char kChromeUIWebAppSettingsURL[] = "chrome://app-settings/";
 inline constexpr char kChromeUIWhatsNewHost[] = "whats-new";
@@ -571,11 +571,11 @@ inline constexpr char kChromeUILinuxProx
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
@@ -600,7 +600,7 @@ inline constexpr char kChromeUIHistorySy
     "chrome://history-sync-optin/";
 #endif
 
-#if ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && \
+#if ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD) || BUILDFLAG(IS_CHROMEOS)) && \
      defined(TOOLKIT_VIEWS)) ||                         \
     defined(USE_AURA)
 inline constexpr char kChromeUITabModalConfirmDialogHost[] =
