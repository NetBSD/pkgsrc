$NetBSD: patch-chrome_browser_signin_signin__util.h,v 1.20 2026/08/09 06:31:10 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/signin/signin_util.h.orig	2026-08-05 20:17:42.000000000 +0000
+++ chrome/browser/signin/signin_util.h
@@ -206,7 +206,7 @@ bool IsSyncingUserSelectableTypesAllowed
     const syncer::SyncService* sync_service,
     const syncer::UserSelectableTypeSet& types);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 // True if the user has explicitly disabled syncing history, tabs or saved tab
 // groups through the settings. The primary account must be set (this crashes
 // otherwise).
