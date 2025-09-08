$NetBSD: patch-chrome_common_url__constants.h,v 1.6 2025/09/08 13:24:22 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/common/url_constants.h.orig	2025-08-29 18:50:09.000000000 +0000
+++ chrome/common/url_constants.h
@@ -993,7 +993,7 @@ inline constexpr char kOutdatedPluginLea
 inline constexpr char kPhoneHubPermissionLearnMoreURL[] =
     "https://support.google.com/chromebook?p=multidevice";
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // "Learn more" URL for the chrome apps deprecation dialog.
 inline constexpr char kChromeAppsDeprecationLearnMoreURL[] =
     "https://support.google.com/chrome?p=chrome_app_deprecation";
