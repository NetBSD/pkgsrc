$NetBSD: patch-chrome_browser_ui_webui_new__tab__page_new__tab__page__handler.cc,v 1.1 2025/08/13 07:44:21 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/webui/new_tab_page/new_tab_page_handler.cc.orig	2025-07-29 22:51:44.000000000 +0000
+++ chrome/browser/ui/webui/new_tab_page/new_tab_page_handler.cc
@@ -540,7 +540,7 @@ NewTabPageHandler::NewTabPageHandler(
       prefs::kNtpFooterVisible,
       base::BindRepeating(&NewTabPageHandler::OnFooterVisibilityUpdated,
                           base::Unretained(this)));
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   local_state_pref_change_registrar_.Init(g_browser_process->local_state());
   local_state_pref_change_registrar_.Add(
       prefs::kNTPFooterManagementNoticeEnabled,
