$NetBSD: patch-chrome_browser_extensions_sync_extension__sync__service.cc,v 1.9 2026/05/10 15:29:49 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/extensions/sync/extension_sync_service.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ chrome/browser/extensions/sync/extension_sync_service.cc
@@ -630,7 +630,7 @@ void ExtensionSyncService::ApplySyncData
     AccountExtensionTracker::Get(profile_)->OnExtensionSyncDataReceived(id);
   }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Chrome Apps are deprecated on WML, so we do not want to sync new apps
   // installed on other devices.
   if (extension_sync_data.is_app()) {
