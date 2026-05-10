$NetBSD: patch-chrome_browser_signin_signin__util.h,v 1.15 2026/05/10 15:29:51 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/signin/signin_util.h.orig	2026-04-28 23:05:57.000000000 +0200
+++ chrome/browser/signin/signin_util.h
@@ -207,7 +207,7 @@ bool IsSyncingUserSelectableTypesAllowed
     const syncer::SyncService* sync_service,
     const syncer::UserSelectableTypeSet& types);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 // True if the user has explicitly disabled syncing history, tabs or saved tab
 // groups through the settings. The primary account must be set (this crashes
 // otherwise).
