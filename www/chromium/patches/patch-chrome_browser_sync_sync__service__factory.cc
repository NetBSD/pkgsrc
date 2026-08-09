$NetBSD: patch-chrome_browser_sync_sync__service__factory.cc,v 1.24 2026/08/09 06:31:10 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/sync/sync_service_factory.cc.orig	2026-08-05 20:17:42.000000000 +0000
+++ chrome/browser/sync/sync_service_factory.cc
@@ -141,7 +141,7 @@ namespace {
 tab_groups::TabGroupSyncService* GetTabGroupSyncService(Profile* profile) {
   CHECK(profile);
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   tab_groups::TabGroupSyncService* service =
       tab_groups::TabGroupSyncServiceFactory::GetForProfile(profile);
   CHECK(service);
@@ -432,7 +432,7 @@ std::unique_ptr<KeyedService> BuildSyncS
   bool local_sync_backend_enabled = false;
   // Only check the local sync backend pref on the supported platforms of
   // Windows, Mac and Linux.
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   syncer::SyncPrefs prefs(profile->GetPrefs());
   local_sync_backend_enabled = prefs.IsLocalSyncEnabled();
   base::UmaHistogramBoolean("Sync.Local.Enabled2", local_sync_backend_enabled);
