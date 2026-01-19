$NetBSD: patch-chrome_browser_ui_webui_history_history__identity__state__watcher.cc,v 1.1 2026/01/19 16:14:11 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/webui/history/history_identity_state_watcher.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ chrome/browser/ui/webui/history/history_identity_state_watcher.cc
@@ -124,7 +124,7 @@ HistoryIdentityStateWatcher::GetSyncStat
   }
   const signin_util::SignedInState signed_in_state =
       signin_util::GetSignedInState(identity_manager_);
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   // if the promo is related to history type, we need to check if any of the
   // History-related types is explicitly disabled via the toggles.
   if (type == syncer::UserSelectableType::kHistory &&
