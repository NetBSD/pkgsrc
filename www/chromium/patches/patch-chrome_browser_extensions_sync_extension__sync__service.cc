$NetBSD: patch-chrome_browser_extensions_sync_extension__sync__service.cc,v 1.4 2026/01/19 16:14:08 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/extensions/sync/extension_sync_service.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ chrome/browser/extensions/sync/extension_sync_service.cc
@@ -594,7 +594,7 @@ void ExtensionSyncService::ApplySyncData
     AccountExtensionTracker::Get(profile_)->OnExtensionSyncDataReceived(id);
   }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Chrome Apps are deprecated on WML, so we do not want to sync new apps
   // installed on other devices.
   if (extension_sync_data.is_app()) {
