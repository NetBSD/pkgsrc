$NetBSD: patch-chrome_browser_ui_webui_search__engine__choice_search__engine__choice__ui.cc,v 1.3 2026/06/08 13:12:36 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/webui/search_engine_choice/search_engine_choice_ui.cc.orig	2026-05-28 23:24:11.000000000 +0000
+++ chrome/browser/ui/webui/search_engine_choice/search_engine_choice_ui.cc
@@ -136,7 +136,7 @@ SearchEngineChoiceUI::SearchEngineChoice
       search_engine_choice_service->IsDsePropagationAllowedForGuest());
 
   const bool is_first_run_desktop_refresh_enabled =
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       switches::IsFirstRunDesktopRefreshEnabled(
           CHECK_DEREF(regional_capabilities_service)
               .IsInSearchEngineChoiceScreenRegion());
