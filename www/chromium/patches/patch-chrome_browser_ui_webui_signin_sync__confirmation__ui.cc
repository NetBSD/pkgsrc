$NetBSD: patch-chrome_browser_ui_webui_signin_sync__confirmation__ui.cc,v 1.1 2026/05/10 15:29:53 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/webui/signin/sync_confirmation_ui.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ chrome/browser/ui/webui/signin/sync_confirmation_ui.cc
@@ -166,7 +166,7 @@ SyncConfirmationUI::SyncConfirmationUI(c
                     IDS_SYNC_LOADING_CONFIRMATION_TITLE);
 
   bool is_first_run_desktop_refresh_enabled = false;
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const bool is_in_search_engine_choice_region =
       CHECK_DEREF(regional_capabilities::RegionalCapabilitiesServiceFactory::
                       GetForProfile(profile_))
