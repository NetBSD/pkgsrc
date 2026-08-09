$NetBSD: patch-remoting_host_setup_me2me__native__messaging__host__main.cc,v 1.22 2026/08/09 06:31:20 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/setup/me2me_native_messaging_host_main.cc.orig	2026-08-05 20:17:42.000000000 +0000
+++ remoting/host/setup/me2me_native_messaging_host_main.cc
@@ -42,7 +42,7 @@
 #include "base/apple/scoped_nsautorelease_pool.h"
 #endif  // BUILDFLAG(IS_APPLE)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "remoting/base/crash/crash_reporting_crashpad.h"
 #include "remoting/base/file_path_util_linux.h"
 #include "remoting/host/pairing_registry_delegate_linux.h"
@@ -105,7 +105,7 @@ int Me2MeNativeMessagingHostMain(int arg
   // needs to be initialized first, so that the preference for crash-reporting
   // can be looked up in the config file.
   if (IsUsageStatsAllowed()) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     InitializeCrashpadReporting();
 #elif BUILDFLAG(IS_WIN)
     InitializeBreakpadReporting();
@@ -273,7 +273,7 @@ int Me2MeNativeMessagingHostMain(int arg
 
   pairing_registry =
       new PairingRegistry(io_thread.task_runner(), std::move(delegate));
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (daemon_controller->is_multi_process()) {
     pairing_registry = base::MakeRefCounted<PairingRegistry>(
         io_thread.task_runner(),
