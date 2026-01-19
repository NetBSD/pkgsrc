$NetBSD: patch-chrome_browser_sync_sync__service__factory.cc,v 1.14 2026/01/19 16:14:10 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/sync/sync_service_factory.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ chrome/browser/sync/sync_service_factory.cc
@@ -134,7 +134,7 @@ namespace {
 tab_groups::TabGroupSyncService* GetTabGroupSyncService(Profile* profile) {
   CHECK(profile);
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   tab_groups::TabGroupSyncService* service =
       tab_groups::TabGroupSyncServiceFactory::GetForProfile(profile);
   CHECK(service);
@@ -401,7 +401,7 @@ std::unique_ptr<KeyedService> BuildSyncS
   bool local_sync_backend_enabled = false;
   // Only check the local sync backend pref on the supported platforms of
   // Windows, Mac and Linux.
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   syncer::SyncPrefs prefs(profile->GetPrefs());
   local_sync_backend_enabled = prefs.IsLocalSyncEnabled();
   base::UmaHistogramBoolean("Sync.Local.Enabled2", local_sync_backend_enabled);
