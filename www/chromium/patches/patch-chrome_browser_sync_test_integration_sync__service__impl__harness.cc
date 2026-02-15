$NetBSD: patch-chrome_browser_sync_test_integration_sync__service__impl__harness.cc,v 1.2 2026/02/15 09:03:59 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/sync/test/integration/sync_service_impl_harness.cc.orig	2026-02-03 22:07:10.000000000 +0000
+++ chrome/browser/sync/test/integration/sync_service_impl_harness.cc
@@ -491,7 +491,7 @@ bool SyncServiceImplHarness::EnableHisto
   // Tabs and history are bundled together in the same toggle.
   service()->GetUserSettings()->SetSelectedType(
       syncer::UserSelectableType::kTabs, true);
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // On desktop platforms, kSavedTabGroups are not merged to kTabs yet, but
   // they're enabled together.
   service()->GetUserSettings()->SetSelectedType(
