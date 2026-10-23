$NetBSD: patch-components_sync_service_sync__prefs.cc,v 1.27 2026/10/23 15:05:25 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/sync/service/sync_prefs.cc.orig	2026-10-19 20:07:21.000000000 +0000
+++ components/sync/service/sync_prefs.cc
@@ -192,7 +192,7 @@ void SyncPrefs::RegisterProfilePrefs(Pre
       prefs::internal::kMigrateExtensionsFromLocalToAccount, false);
   registry->RegisterBooleanPref(
       prefs::internal::kMigrateThemeFromLocalToAccount, false);
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   registry->RegisterBooleanPref(
       prefs::internal::kReadingListPrefMigratedToAccount, false);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
@@ -869,7 +869,7 @@ bool SyncPrefs::MaybeMigratePrefsForSync
           update_selected_types_dict->EnsureDict(
               signin::GaiaIdHash::FromGaiaId(gaia_id).ToBase64());
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       // Preserve the user's existing enabled state for Bookmarks, Reading List,
       // and Preferences. Otherwise, use the default value, which will be true
       // after `kReplaceSyncPromosWithSignInPromos`.
@@ -1062,7 +1062,7 @@ void SyncPrefs::MigrateGlobalDataTypePre
                         saved_tab_groups_enabled);
   account_settings->Set(GetPrefNameForType(UserSelectableType::kExtensions),
                         extensions_enabled);
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Record that this migration now covers the Reading List toggle, to be able
   // to identify users who were migrated before it did (crbug.com/568406887).
   pref_service->SetBoolean(prefs::internal::kReadingListPrefMigratedToAccount,
