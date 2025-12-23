$NetBSD: patch-chrome_browser_signin_signin__util.h,v 1.9 2025/12/23 13:22:14 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/signin/signin_util.h.orig	2025-12-17 23:05:18.000000000 +0000
+++ chrome/browser/signin/signin_util.h
@@ -203,7 +203,7 @@ bool IsSyncingUserSelectableTypesAllowed
     const syncer::SyncService* sync_service,
     const syncer::UserSelectableTypeSet& types);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 // True if the user has explicitly disabled syncing history, tabs or saved tab
 // groups through the settings.
 // This method does not take into account the feature flag
