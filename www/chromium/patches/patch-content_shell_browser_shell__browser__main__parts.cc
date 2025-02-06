$NetBSD: patch-content_shell_browser_shell__browser__main__parts.cc,v 1.1 2025/02/06 09:58:08 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/shell/browser/shell_browser_main_parts.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ content/shell/browser/shell_browser_main_parts.cc
@@ -51,7 +51,7 @@
 #include "net/base/network_change_notifier.h"
 #endif
 
-#if defined(USE_AURA) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+#if defined(USE_AURA) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD))
 #include "ui/base/ime/init/input_method_initializer.h"
 #endif
 
@@ -68,7 +68,7 @@
 #include "chromeos/lacros/dbus/lacros_dbus_thread_manager.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/linux/linux_ui.h"          // nogncheck
 #include "ui/linux/linux_ui_factory.h"  // nogncheck
 #endif
@@ -139,7 +139,7 @@ void ShellBrowserMainParts::PostCreateMa
 }
 
 int ShellBrowserMainParts::PreEarlyInitialization() {
-#if defined(USE_AURA) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+#if defined(USE_AURA) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD))
   ui::InitializeInputMethodForTesting();
 #endif
 #if BUILDFLAG(IS_ANDROID)
@@ -168,7 +168,7 @@ void ShellBrowserMainParts::ToolkitIniti
   if (switches::IsRunWebTestsSwitchPresent())
     return;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   ui::LinuxUi::SetInstance(ui::GetDefaultLinuxUi());
 #endif
 }
@@ -215,7 +215,7 @@ void ShellBrowserMainParts::PostMainMess
   ShellDevToolsManagerDelegate::StopHttpHandler();
   browser_context_.reset();
   off_the_record_browser_context_.reset();
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   ui::LinuxUi::SetInstance(nullptr);
 #endif
   performance_manager_lifetime_.reset();
