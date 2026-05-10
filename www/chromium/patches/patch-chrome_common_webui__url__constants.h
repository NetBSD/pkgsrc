$NetBSD: patch-chrome_common_webui__url__constants.h,v 1.19 2026/05/10 15:29:54 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/common/webui_url_constants.h.orig	2026-04-28 23:05:57.000000000 +0200
+++ chrome/common/webui_url_constants.h
@@ -442,12 +442,12 @@ bool IsSystemWebUIHost(std::string_view 
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_DESKTOP_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_DESKTOP_ANDROID) || BUILDFLAG(IS_BSD)
 inline constexpr char kChromeUIDiscardsHost[] = "discards";
 inline constexpr char kChromeUIDiscardsURL[] = "chrome://discards/";
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 inline constexpr char kChromeUIDefaultBrowserModalURL[] =
     "chrome://default-browser-modal/";
 inline constexpr char kChromeUIDefaultBrowserModalHost[] =
@@ -463,11 +463,11 @@ inline constexpr char kChromeUILinuxProx
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
@@ -497,7 +497,7 @@ inline constexpr char kChromeUIUpdaterHo
 inline constexpr char kChromeUIUpdaterURL[] = "chrome://updater/";
 #endif
 
-#if ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && \
+#if ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) && \
      defined(TOOLKIT_VIEWS)) ||                         \
     defined(USE_AURA)
 inline constexpr char kChromeUITabModalConfirmDialogHost[] =
