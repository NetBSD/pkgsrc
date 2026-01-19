$NetBSD: patch-chrome_browser_sync_test_integration_sync__service__impl__harness.cc,v 1.1 2026/01/19 16:14:10 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/sync/test/integration/sync_service_impl_harness.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ chrome/browser/sync/test/integration/sync_service_impl_harness.cc
@@ -486,7 +486,7 @@ bool SyncServiceImplHarness::EnableHisto
   // Tabs and history are bundled together in the same toggle.
   service()->GetUserSettings()->SetSelectedType(
       syncer::UserSelectableType::kTabs, true);
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // On desktop platforms, kSavedTabGroups are not merged to kTabs yet, but
   // they're enabled together.
   service()->GetUserSettings()->SetSelectedType(
