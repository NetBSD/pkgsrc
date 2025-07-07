$NetBSD: patch-components_sync__preferences_common__syncable__prefs__database.cc,v 1.2 2025/07/07 09:23:31 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/sync_preferences/common_syncable_prefs_database.cc.orig	2025-06-30 06:54:11.000000000 +0000
+++ components/sync_preferences/common_syncable_prefs_database.cc
@@ -339,7 +339,7 @@ constexpr auto kCommonSyncablePrefsAllow
           PrefSensitivity::kNone, MergeBehavior::kNone}},
 #endif  // BUILDFLAG(IS_ANDROID)
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
         {autofill::prefs::kAutofillBnplEnabled,
          {syncable_prefs_ids::kAutofillBnplEnabled, syncer::PREFERENCES,
           PrefSensitivity::kNone, MergeBehavior::kNone}},
