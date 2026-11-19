$NetBSD: patch-chrome_browser_ui_webui_infobar__internals_infobar__internals__handler.cc,v 1.20 2026/11/19 19:45:56 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/webui/infobar_internals/infobar_internals_handler.cc.orig	2026-11-11 21:01:38.000000000 +0000
+++ chrome/browser/ui/webui/infobar_internals/infobar_internals_handler.cc
@@ -103,7 +103,7 @@
 #include "chrome/browser/ui/cocoa/keystone_infobar_delegate.h"
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/apps/link_capturing/enable_link_capturing_infobar_delegate.h"
 #include "chrome/browser/ui/startup/default_browser_prompt/default_browser_prompt_manager.h"
 #include "chrome/browser/ui/startup/default_browser_prompt/default_browser_prompt_prefs.h"
@@ -170,7 +170,7 @@ TriggerRequirements RequirementsFor(Info
     case InfoBarType::kSigninQRCode:
 #endif
       return {.web_contents = true};
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     case InfoBarType::kEnableLinkCapturing:
       return {.profile = true, .web_contents = true};
 #endif
@@ -181,7 +181,7 @@ TriggerRequirements RequirementsFor(Info
       return {.profile = true, .web_contents = true};
 #endif
     case InfoBarType::kExtensionDevTools:
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     case InfoBarType::kDefaultBrowser:
     case InfoBarType::kSessionRestore:
 #endif
@@ -300,7 +300,7 @@ void InfoBarInternalsHandler::GetInfoBar
             "The Collected Cookies infobar is shown after the user has changed "
             "the allowed/blocked state of a cookie, reminding them to reload "
             "the page in order for the new cookies to take effect.");
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   add_entry(InfoBarType::kDefaultBrowser, "Default Browser",
             "The Default Browser infobar asks the user if they want to set "
             "Chrome as their default browser. This trigger resets any browser "
@@ -324,7 +324,7 @@ void InfoBarInternalsHandler::GetInfoBar
             "process-per-site disabled. This trigger shows the infobar on the "
             "active tab.");
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   add_entry(InfoBarType::kEnableLinkCapturing, "Enable Link Capturing",
             "The Enable Link Capturing infobar asks the user if they want to "
             "open supported links in an installed web app. This trigger "
@@ -416,7 +416,7 @@ void InfoBarInternalsHandler::GetInfoBar
             "Mac.");
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   add_entry(InfoBarType::kSessionRestore, "Session Restore",
             "Triggers the session restore infobar. This infobar can only be "
             "triggered on Mac, Windows and Linux.");
@@ -562,7 +562,7 @@ bool InfoBarInternalsHandler::PerformInf
       }
       return true;
     }
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     case InfoBarType::kDefaultBrowser: {
       chrome::startup::default_prompt::ResetPromptPrefs(profile);
       DefaultBrowserPromptManager::GetInstance()->MaybeShowPrompt();
@@ -619,7 +619,7 @@ bool InfoBarInternalsHandler::PerformInf
                  std::make_unique<ProcessSharingInfobarDelegate>(
                      web_contents))) != nullptr;
     }
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     case InfoBarType::kEnableLinkCapturing: {
       std::string app_id = "example_app_id";
       std::u16string app_name = u"Example App";
@@ -1020,7 +1020,7 @@ bool InfoBarInternalsHandler::PerformInf
     }
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     case InfoBarType::kSessionRestore: {
       session_restore_infobar::SessionRestoreInfoBarManager::GetInstance()
           ->ShowInfoBar(
