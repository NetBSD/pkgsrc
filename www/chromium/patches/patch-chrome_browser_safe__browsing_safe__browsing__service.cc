$NetBSD: patch-chrome_browser_safe__browsing_safe__browsing__service.cc,v 1.11 2026/09/02 13:13:24 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/safe_browsing/safe_browsing_service.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ chrome/browser/safe_browsing/safe_browsing_service.cc
@@ -81,7 +81,7 @@
 #include "services/preferences/public/mojom/tracked_preference_validation_delegate.mojom.h"
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/safe_browsing/security_settings_bundle_toast_helper.h"
 #endif
 
@@ -172,7 +172,7 @@ void TriggerSecuritySettingsBundleToastI
   }
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   if (GetSecurityBundleSetting(*profile->GetPrefs()) ==
       SecuritySettingsBundleSetting::ENHANCED) {
     SecuritySettingsBundleToastHelper::GetForProfile(profile.get())
