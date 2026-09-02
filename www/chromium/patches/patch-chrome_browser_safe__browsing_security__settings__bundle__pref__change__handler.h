$NetBSD: patch-chrome_browser_safe__browsing_security__settings__bundle__pref__change__handler.h,v 1.5 2026/09/02 13:13:24 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/safe_browsing/security_settings_bundle_pref_change_handler.h.orig	2026-08-31 22:47:51.000000000 +0000
+++ chrome/browser/safe_browsing/security_settings_bundle_pref_change_handler.h
@@ -8,7 +8,7 @@
 #include "base/memory/raw_ptr.h"
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/toasts/toast_controller.h"
 #endif
 
@@ -25,13 +25,13 @@ class SecuritySettingsBundlePrefChangeHa
   virtual void MaybeShowEnhancedBundleSettingChangeNotification();
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   void SetToastControllerForTesting(ToastController* controller);
 #endif
 
  private:
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   ToastController* GetToastController();
 #endif
 
@@ -39,7 +39,7 @@ class SecuritySettingsBundlePrefChangeHa
   raw_ptr<Profile> profile_ = nullptr;
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   raw_ptr<ToastController> toast_controller_for_testing_ = nullptr;
 #endif
 };
