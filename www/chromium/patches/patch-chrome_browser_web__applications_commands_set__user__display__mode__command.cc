$NetBSD: patch-chrome_browser_web__applications_commands_set__user__display__mode__command.cc,v 1.15 2026/02/15 09:04:01 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/web_applications/commands/set_user_display_mode_command.cc.orig	2026-02-03 22:07:10.000000000 +0000
+++ chrome/browser/web_applications/commands/set_user_display_mode_command.cc
@@ -65,7 +65,7 @@ void SetUserDisplayModeCommand::StartWit
     // OsIntegrationTestOverride can use the xdg install command to detect
     // install.
     SynchronizeOsOptions options;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     options.add_shortcut_to_desktop = true;
 #endif
     app_lock_->os_integration_manager().Synchronize(
