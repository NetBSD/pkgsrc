$NetBSD: patch-chrome_browser_ui_webui_infobar__internals_infobar__internals__handler.cc,v 1.13 2026/09/22 13:41:22 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/webui/infobar_internals/infobar_internals_handler.cc.orig	2026-09-14 22:17:16.000000000 +0000
+++ chrome/browser/ui/webui/infobar_internals/infobar_internals_handler.cc
@@ -79,7 +79,7 @@
 #include "chrome/browser/ui/cocoa/keystone_infobar_delegate.h"
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/startup/default_browser_prompt/default_browser_prompt_manager.h"  // nogncheck
 #include "chrome/browser/ui/startup/default_browser_prompt/default_browser_prompt_prefs.h"  // nogncheck
 #include "chrome/browser/ui/views/session_restore_infobar/session_restore_infobar_delegate.h"
@@ -133,7 +133,7 @@ void InfoBarInternalsHandler::GetInfoBar
       "The Collected Cookies infobar is shown after the user has changed "
       "the allowed/blocked state of a cookie, reminding them to reload "
       "the page in order for the new cookies to take effect."));
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   infobar_list.emplace_back(InfoBarEntry::New(
       /*type=*/InfoBarType::kDefaultBrowser, /*name=*/"Default Browser",
       /*description=*/
@@ -304,7 +304,7 @@ bool InfoBarInternalsHandler::TriggerInf
       }
       return true;
     }
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     case InfoBarType::kDefaultBrowser: {
       if (!profile) {
         return false;
