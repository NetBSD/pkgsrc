$NetBSD: patch-chrome_browser_ui_views_new__tab__footer_footer__controller.cc,v 1.12 2026/01/19 16:14:11 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/new_tab_footer/footer_controller.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ chrome/browser/ui/views/new_tab_footer/footer_controller.cc
@@ -44,7 +44,7 @@ NewTabFooterController::NewTabFooterCont
       base::BindRepeating(&NewTabFooterController::UpdateFooterVisibilities,
                           weak_factory_.GetWeakPtr(),
                           /*log_on_load_metric=*/false));
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   local_state_pref_change_registrar_.Init(g_browser_process->local_state());
   local_state_pref_change_registrar_.Add(
       prefs::kNTPFooterManagementNoticeEnabled,
