$NetBSD: patch-chrome_browser_ui_webui_infobar__internals_infobar__internals__handler.cc,v 1.3 2026/03/14 12:40:29 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/webui/infobar_internals/infobar_internals_handler.cc.orig	2026-03-11 22:12:25.000000000 +0000
+++ chrome/browser/ui/webui/infobar_internals/infobar_internals_handler.cc
@@ -26,7 +26,7 @@
 #include "chrome/browser/win/installer_downloader/installer_downloader_pref_names.h"
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/startup/default_browser_prompt/default_browser_prompt_manager.h"  // nogncheck
 #include "chrome/browser/ui/startup/default_browser_prompt/default_browser_prompt_prefs.h"  // nogncheck
 #include "chrome/browser/ui/views/session_restore_infobar/session_restore_infobar_delegate.h"
@@ -55,7 +55,7 @@ void InfoBarInternalsHandler::TriggerInf
 
 void InfoBarInternalsHandler::GetInfoBars(GetInfoBarsCallback callback) {
   std::vector<InfoBarEntryPtr> infobar_list;
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   infobar_list.emplace_back(InfoBarEntry::New(
       /*type=*/InfoBarType::kDefaultBrowser, /*name=*/"Default Browser",
       /*description=*/
@@ -94,7 +94,7 @@ void InfoBarInternalsHandler::GetInfoBar
 
 bool InfoBarInternalsHandler::TriggerInfoBarInternal(InfoBarType type) {
   switch (type) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     case InfoBarType::kDefaultBrowser: {
       BrowserWindowInterface* const bwi =
           GetLastActiveBrowserWindowInterfaceWithAnyProfile();
