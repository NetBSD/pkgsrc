$NetBSD: patch-chrome_common_url__constants.h,v 1.19 2026/05/10 15:29:54 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/common/url_constants.h.orig	2026-04-28 23:05:57.000000000 +0200
+++ chrome/common/url_constants.h
@@ -729,7 +729,7 @@ inline constexpr char kOutdatedPluginLea
     "https://support.google.com/chrome?p=ib_outdated_plugin";
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // "Learn more" URL for the chrome apps deprecation dialog.
 inline constexpr char kChromeAppsDeprecationLearnMoreURL[] =
     "https://support.google.com/chrome?p=chrome_app_deprecation";
