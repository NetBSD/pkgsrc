$NetBSD: patch-chrome_browser_web__applications_commands_set__user__display__mode__command.cc,v 1.6 2025/09/08 13:24:21 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/web_applications/commands/set_user_display_mode_command.cc.orig	2025-08-29 18:50:09.000000000 +0000
+++ chrome/browser/web_applications/commands/set_user_display_mode_command.cc
@@ -56,7 +56,7 @@ void SetUserDisplayModeCommand::StartWit
     // OsIntegrationTestOverride can use the xdg install command to detect
     // install.
     SynchronizeOsOptions options;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     options.add_shortcut_to_desktop = true;
 #endif
     app_lock_->os_integration_manager().Synchronize(
