$NetBSD: patch-chrome_browser_global__features.cc,v 1.23 2026/07/08 13:42:16 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/global_features.cc.orig	2026-07-06 22:58:46.000000000 +0000
+++ chrome/browser/global_features.cc
@@ -38,7 +38,7 @@
 #include "chrome/browser/background/glic/glic_background_mode_manager.h"  // nogncheck
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // This causes a gn error on Android builds, because gn does not understand
 // buildflags, so we include it only on platforms where it is used.
 #include "chrome/browser/default_browser/default_browser_manager.h"
@@ -175,7 +175,7 @@ void GlobalFeatures::PostBrowserProcessI
             *g_browser_process, g_browser_process);
   }
   system_permissions_platform_handle_ = CreateSystemPermissionsPlatformHandle();
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // TODO(crbug.com/463742800): Migrate WhatsNewRegistry (and other non-core
   // features) to Init().
   whats_new_registry_ = CreateWhatsNewRegistry();
@@ -249,7 +249,7 @@ void GlobalFeatures::PostMainMessageLoop
 
   application_advanced_protection_status_detector_.reset();
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   DefaultBrowserPromptManager::GetInstance()->CloseAllPrompts(
       DefaultBrowserPromptManager::CloseReason::kDismiss);
 #endif
@@ -268,7 +268,7 @@ GlobalFeatures::CreateSystemPermissionsP
   return system_permission_settings::PlatformHandle::Create();
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 std::unique_ptr<whats_new::WhatsNewRegistry>
 GlobalFeatures::CreateWhatsNewRegistry() {
   return whats_new::CreateWhatsNewRegistry();
