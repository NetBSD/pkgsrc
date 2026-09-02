$NetBSD: patch-chrome_browser_sync_test_integration_sync__service__impl__harness.cc,v 1.12 2026/09/02 13:13:24 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/sync/test/integration/sync_service_impl_harness.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ chrome/browser/sync/test/integration/sync_service_impl_harness.cc
@@ -489,7 +489,7 @@ bool SyncServiceImplHarness::EnableHisto
   // Tabs and history are bundled together in the same toggle.
   service()->GetUserSettings()->SetSelectedType(
       syncer::UserSelectableType::kTabs, true);
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // On desktop platforms, kSavedTabGroups are not merged to kTabs yet, but
   // they're enabled together.
   service()->GetUserSettings()->SetSelectedType(
