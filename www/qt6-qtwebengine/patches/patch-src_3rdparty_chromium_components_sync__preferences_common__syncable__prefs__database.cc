$NetBSD: patch-src_3rdparty_chromium_components_sync__preferences_common__syncable__prefs__database.cc,v 1.1 2026/04/30 06:39:39 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/components/sync_preferences/common_syncable_prefs_database.cc.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/components/sync_preferences/common_syncable_prefs_database.cc
@@ -337,7 +337,7 @@ constexpr auto kCommonSyncablePrefsAllow
           syncer::PREFERENCES, PrefSensitivity::kNone, MergeBehavior::kNone}},
 #endif  // BUILDFLAG(IS_ANDROID)
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
         {autofill::prefs::kAutofillBnplEnabled,
          {syncable_prefs_ids::kAutofillBnplEnabled, syncer::PREFERENCES,
           PrefSensitivity::kNone, MergeBehavior::kNone}},
