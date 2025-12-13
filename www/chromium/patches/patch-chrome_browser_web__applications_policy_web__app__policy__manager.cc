$NetBSD: patch-chrome_browser_web__applications_policy_web__app__policy__manager.cc,v 1.12 2025/12/13 14:53:52 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/web_applications/policy/web_app_policy_manager.cc.orig	2025-11-19 21:40:05.000000000 +0000
+++ chrome/browser/web_applications/policy/web_app_policy_manager.cc
@@ -135,7 +135,7 @@ GetPreinstalledWebAppsMappingForTesting(
 namespace web_app {
 
 BASE_FEATURE(kDesktopPWAsForceUnregisterOSIntegration,
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
