$NetBSD: patch-chrome_browser_web__applications_commands_launch__web__app__command.cc,v 1.28 2026/10/02 11:43:26 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/web_applications/commands/launch_web_app_command.cc.orig	2026-09-22 00:09:16.000000000 +0000
+++ chrome/browser/web_applications/commands/launch_web_app_command.cc
@@ -111,7 +111,7 @@ void LaunchWebAppCommand::StartWithLock(
     // OsIntegrationTestOverride can use the xdg install command to detect
     // install.
     SynchronizeOsOptions options;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     options.add_shortcut_to_desktop = true;
 #endif
     lock_->os_integration_manager().Synchronize(
