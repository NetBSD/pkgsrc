$NetBSD: patch-chrome_browser_apps_platform__apps_platform__app__launch.cc,v 1.14 2026/01/19 16:14:07 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/apps/platform_apps/platform_app_launch.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ chrome/browser/apps/platform_apps/platform_app_launch.cc
@@ -19,7 +19,7 @@
 #include "extensions/common/constants.h"
 #include "extensions/common/extension.h"
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/browser.h"
 #include "chrome/browser/ui/browser_navigator.h"
 #include "chrome/browser/ui/browser_window.h"
@@ -86,7 +86,7 @@ bool OpenExtensionApplicationWindow(Prof
   if (launch_container == LaunchContainer::kLaunchContainerTab)
     return false;
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (OpenDeprecatedApplicationPrompt(profile, app_id)) {
     return false;
   }
@@ -118,7 +118,7 @@ content::WebContents* OpenExtensionAppli
   if (launch_container != apps::LaunchContainer::kLaunchContainerTab)
     return nullptr;
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (OpenDeprecatedApplicationPrompt(profile, app_id)) {
     return nullptr;
   }
@@ -134,7 +134,7 @@ content::WebContents* OpenExtensionAppli
   return app_tab;
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool OpenDeprecatedApplicationPrompt(Profile* profile,
                                      const std::string& app_id) {
   if (!extensions::IsExtensionUnsupportedDeprecatedApp(profile, app_id))
@@ -170,7 +170,7 @@ bool OpenExtensionApplicationWithReenabl
   if (!GetPlatformApp(profile, app_id))
     return false;
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (OpenDeprecatedApplicationPrompt(profile, app_id)) {
     return false;
   }
@@ -192,7 +192,7 @@ content::WebContents* OpenExtensionAppSh
                                          ->enabled_extensions()
                                          .GetAppByURL(url);
   if (app) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     if (OpenDeprecatedApplicationPrompt(profile, app->id())) {
       return nullptr;
     }
@@ -215,7 +215,7 @@ void RecordExtensionAppLaunchOnTabRestor
   if (!extension)
     return;
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (OpenDeprecatedApplicationPrompt(profile, extension->id())) {
     return;
   }
