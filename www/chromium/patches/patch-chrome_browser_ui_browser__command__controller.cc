$NetBSD: patch-chrome_browser_ui_browser__command__controller.cc,v 1.19 2026/05/10 15:29:51 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/browser_command_controller.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ chrome/browser/ui/browser_command_controller.cc
@@ -155,7 +155,7 @@
 #include "components/user_manager/user_manager.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/base/ime/text_edit_commands.h"
 #include "ui/base/ime/text_input_flags.h"
 #include "ui/linux/linux_ui.h"
@@ -165,7 +165,7 @@
 #include "ui/ozone/public/ozone_platform.h"
 #endif
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/shortcuts/desktop_shortcuts_utils.h"
 #endif  // BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
 
@@ -441,7 +441,7 @@ bool BrowserCommandController::IsReserve
 #endif
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // If this key was registered by the user as a content editing hotkey, then
   // it is not reserved.
   auto* linux_ui = ui::LinuxUi::instance();
@@ -756,7 +756,7 @@ bool BrowserCommandController::ExecuteCo
       break;
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     case IDC_MINIMIZE_WINDOW:
       browser_->window()->Minimize();
       break;
@@ -996,7 +996,7 @@ bool BrowserCommandController::ExecuteCo
       break;
     case IDC_CREATE_SHORTCUT:
       base::RecordAction(base::UserMetricsAction("CreateShortcut"));
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       chrome::CreateDesktopShortcutForActiveWebContents(browser_);
 #else
       web_app::CreateWebAppFromCurrentWebContents(
@@ -1188,7 +1188,7 @@ bool BrowserCommandController::ExecuteCo
 #endif  // BUILDFLAG(GOOGLE_CHROME_BRANDING)
     case IDC_CHROME_WHATS_NEW:
 #if BUILDFLAG(GOOGLE_CHROME_BRANDING) && \
-    (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX))
+    (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
       ShowChromeWhatsNew(browser_);
       break;
 #else
@@ -1588,7 +1588,7 @@ void BrowserCommandController::InitComma
   command_updater_.UpdateCommandEnabled(IDC_VISIT_DESKTOP_OF_LRU_USER_4, true);
   command_updater_.UpdateCommandEnabled(IDC_VISIT_DESKTOP_OF_LRU_USER_5, true);
 #endif
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   command_updater_.UpdateCommandEnabled(IDC_MINIMIZE_WINDOW, true);
   command_updater_.UpdateCommandEnabled(IDC_MAXIMIZE_WINDOW, true);
   command_updater_.UpdateCommandEnabled(IDC_RESTORE_WINDOW, true);
@@ -1970,7 +1970,7 @@ void BrowserCommandController::UpdateCom
   bool can_create_web_app = web_app::CanCreateWebApp(browser_);
   command_updater_.UpdateCommandEnabled(IDC_INSTALL_PWA, can_create_web_app);
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   command_updater_.UpdateCommandEnabled(
       IDC_CREATE_SHORTCUT,
       shortcuts::CanCreateDesktopShortcut(current_web_contents));
