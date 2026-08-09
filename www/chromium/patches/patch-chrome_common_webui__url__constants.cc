$NetBSD: patch-chrome_common_webui__url__constants.cc,v 1.24 2026/08/09 06:31:13 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/common/webui_url_constants.cc.orig	2026-08-05 20:17:42.000000000 +0000
+++ chrome/common/webui_url_constants.cc
@@ -189,7 +189,7 @@ base::span<const base::cstring_view> Chr
       kChromeUITermsHost,
 #endif
       kChromeUITranslateInternalsHost,
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       kChromeUIUpdaterHost,
 #endif
       kChromeUIUsbInternalsHost,
@@ -257,17 +257,17 @@ base::span<const base::cstring_view> Chr
       ash::kChromeUIInternetDetailDialogHost,
 #endif
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_DESKTOP_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_DESKTOP_ANDROID) || BUILDFLAG(IS_BSD)
       kChromeUIDiscardsHost,
 #endif
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       kChromeUIWebAppSettingsHost,
 #endif
 #if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_ANDROID)
       kChromeUILinuxProxyConfigHost,
 #endif
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
       kChromeUISandboxHost,
 #endif
 #if BUILDFLAG(IS_WIN)
