$NetBSD: patch-components_sync_base_pref__names.h,v 1.2 2026/11/08 15:39:01 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/sync/base/pref_names.h.orig	2026-11-02 23:22:33.000000000 +0000
+++ components/sync/base/pref_names.h
@@ -146,7 +146,7 @@ inline constexpr char kMigrateExtensions
 inline constexpr char kMigrateThemeFromLocalToAccount[] =
     "sync.migrate_theme_from_local_to_account";
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Whether SyncPrefs::MigrateGlobalDataTypePrefsToAccount() ran with the Reading
 // List toggle included (see crbug.com/568406887).
 inline constexpr char kReadingListPrefMigratedToAccount[] =
