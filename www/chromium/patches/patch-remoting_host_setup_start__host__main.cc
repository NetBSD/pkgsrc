$NetBSD: patch-remoting_host_setup_start__host__main.cc,v 1.22 2026/07/06 13:06:56 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/setup/start_host_main.cc.orig	2026-06-23 23:37:18.000000000 +0000
+++ remoting/host/setup/start_host_main.cc
@@ -44,7 +44,7 @@
 #include <unistd.h>
 #endif  // BUILDFLAG(IS_POSIX)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "remoting/base/crash/crash_reporting_crashpad.h"
 #include "remoting/host/linux/host_types.h"
 #include "remoting/host/setup/daemon_controller_delegate_linux_single_process.h"
@@ -91,7 +91,7 @@ constexpr char kDisableCrashReportingSwi
 constexpr char kInvalidPinErrorMessage[] =
     "Please provide a numeric PIN consisting of at least six digits.\n";
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // The host type to use.
 constexpr char kHostTypeSwitchName[] = "host-type";
 #endif
@@ -118,7 +118,7 @@ void PrintDefaultHelpMessage(const char*
       process_name, kAuthCodeSwitchName, kRedirectUrlSwitchName,
       kDisplayNameSwitchName, kPinSwitchName, kDisableCrashReportingSwitchName);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::cerr << base::StringPrintf(" [--%s=<host type>]", kHostTypeSwitchName)
             << "\n\n";
   HostType::PrintHostTypeHelp();
@@ -424,7 +424,7 @@ int StartHostMain(int argc, char** argv)
   }
 #endif  // defined(REMOTING_ENABLE_CRASH_REPORTING)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const HostType* host_type = nullptr;
   if (command_line->HasSwitch(kHostTypeSwitchName)) {
     std::string host_type_name =
@@ -473,7 +473,7 @@ int StartHostMain(int argc, char** argv)
   }
 #endif  // BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (command_line->HasSwitch("no-start")) {
     // On Linux, registering the host with systemd and starting it is the only
     // reason start_host requires root. The --no-start options skips that final
