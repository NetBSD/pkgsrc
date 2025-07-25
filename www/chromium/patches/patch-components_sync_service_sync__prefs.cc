$NetBSD: patch-components_sync_service_sync__prefs.cc,v 1.2 2025/07/25 16:17:16 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/sync/service/sync_prefs.cc.orig	2025-07-21 19:32:31.000000000 +0000
+++ components/sync/service/sync_prefs.cc
@@ -776,7 +776,7 @@ bool SyncPrefs::IsTypeSupportedInTranspo
       // transport mode everywhere.
       return true;
     case UserSelectableType::kHistory:
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       return base::FeatureList::IsEnabled(kReplaceSyncPromosWithSignInPromos) ||
              base::FeatureList::IsEnabled(switches::kEnableHistorySyncOptin);
 #else
