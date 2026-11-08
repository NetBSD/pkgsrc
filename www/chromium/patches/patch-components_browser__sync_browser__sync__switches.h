$NetBSD: patch-components_browser__sync_browser__sync__switches.h,v 1.1 2026/11/08 15:38:59 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/browser_sync/browser_sync_switches.h.orig	2026-11-02 23:22:33.000000000 +0000
+++ components/browser_sync/browser_sync_switches.h
@@ -58,7 +58,7 @@ BASE_DECLARE_FEATURE(kForceMigrateNoopFo
 BASE_DECLARE_FEATURE(kMigrateOutOfSyncSetupIncompleteState);
 #endif  // !BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // If enabled, users who were migrated from syncing to signed-in before the
 // migration carried over the Reading List toggle get Reading List enabled at
 // browser startup (see crbug.com/568406887).
