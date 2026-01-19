$NetBSD: patch-chrome_app_chrome__main__delegate.cc,v 1.14 2026/01/19 16:14:07 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/app/chrome_main_delegate.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ chrome/app/chrome_main_delegate.cc
@@ -100,7 +100,7 @@
 #include "ui/base/ui_base_switches.h"
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 #include "components/webapps/isolated_web_apps/scheme.h"
 #endif
 
@@ -179,17 +179,17 @@
 #include "v8/include/v8.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD) 
 #include "base/environment.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/nix/scoped_xdg_activation_token_injector.h"
 #include "ui/linux/display_server_utils.h"
 #endif
 
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_ANDROID) || \
-    BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/policy/policy_path_parser.h"
 #include "components/crash/core/app/crashpad.h"
 #endif
@@ -223,7 +223,7 @@ const char* const ChromeMainDelegate::kN
 #endif
     chrome::kChromeSearchScheme,
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
     webapps::kIsolatedAppScheme,
 #endif
     content::kChromeDevToolsScheme,    content::kChromeUIScheme,
@@ -298,7 +298,7 @@ void AdjustLinuxOOMScore(const std::stri
 // and resources loaded.
 bool SubprocessNeedsResourceBundle(const std::string& process_type) {
   return
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
       // The zygote process opens the resources for the renderers.
       process_type == switches::kZygoteProcess ||
 #endif
@@ -378,7 +378,7 @@ bool HandleVersionSwitches(const base::C
   return false;
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Show the man page if --help or -h is on the command line.
 void HandleHelpSwitches(const base::CommandLine& command_line) {
   if (command_line.HasSwitch(switches::kHelp) ||
@@ -390,7 +390,7 @@ void HandleHelpSwitches(const base::Comm
 }
 #endif  // BUILDFLAG(IS_LINUX)
 
-#if !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_ANDROID)
+#if !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_BSD)
 void SIGTERMProfilingShutdown(int signal) {
   content::Profiling::Stop();
   struct sigaction sigact;
@@ -472,7 +472,7 @@ std::optional<int> AcquireProcessSinglet
   // process can be exited.
   ChromeProcessSingleton::CreateInstance(user_data_dir);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Read the xdg-activation token and set it in the command line for the
   // duration of the notification in order to ensure this is propagated to an
   // already running browser process if it exists.
@@ -550,7 +550,7 @@ void InitializeUserDataDir(base::Command
   std::string process_type =
       command_line->GetSwitchValueASCII(switches::kProcessType);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // On Linux, Chrome does not support running multiple copies under different
   // DISPLAYs, so the profile directory can be specified in the environment to
   // support the virtual desktop use-case.
@@ -656,7 +656,7 @@ void RecordMainStartupMetrics(const Star
 #endif
 
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Record the startup process creation time on supported platforms. On Android
   // this is recorded in ChromeMainDelegateAndroid.
   startup_metric_utils::GetCommon().RecordStartupProcessCreationTime(
@@ -815,7 +815,7 @@ std::optional<int> ChromeMainDelegate::P
 #if BUILDFLAG(IS_OZONE)
   // Initialize Ozone platform and add required feature flags as per platform's
   // properties.
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   ui::SetOzonePlatformForLinuxIfNeeded(*base::CommandLine::ForCurrentProcess());
 #endif
   ui::OzonePlatform::PreEarlyInitialization();
@@ -971,7 +971,7 @@ void ChromeMainDelegate::CommonEarlyInit
 
   const bool emit_crashes =
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
       IsCanaryDev();
 #else
       false;
@@ -1113,7 +1113,7 @@ std::optional<int> ChromeMainDelegate::B
     return 0;  // Got a --credits switch; exit with a success error code.
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // This will directly exit if the user asked for help.
   HandleHelpSwitches(command_line);
 #endif
@@ -1426,7 +1426,7 @@ void ChromeMainDelegate::PreSandboxStart
     CHECK(!loaded_locale.empty()) << "Locale could not be found for " << locale;
   }
 
-#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_BSD)
   // Zygote needs to call InitCrashReporter() in RunZygote().
   if (process_type != switches::kZygoteProcess &&
       !command_line.HasSwitch(switches::kDisableCrashpadForTesting)) {
