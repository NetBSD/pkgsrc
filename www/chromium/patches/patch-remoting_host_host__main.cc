$NetBSD: patch-remoting_host_host__main.cc,v 1.17 2026/04/10 17:31:57 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/host_main.cc.orig	2026-04-06 16:25:54.000000000 +0000
+++ remoting/host/host_main.cc
@@ -47,7 +47,7 @@ namespace remoting {
 // Known entry points.
 int SingleProcessHostProcessMain();
 int NetworkProcessMain();
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 int DaemonProcessMain();
 int DesktopProcessMain();
 #endif
@@ -56,7 +56,7 @@ int FileChooserMain();
 int RdpDesktopSessionMain();
 int UrlForwarderConfiguratorMain();
 #endif  // BUILDFLAG(IS_WIN)
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 int XSessionChooserMain();
 int UserSystemdEnvMain();
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
@@ -71,7 +71,7 @@ void Usage(const base::FilePath& program
       "\n"
       "Options:\n"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       "  --audio-pipe-name=<pipe> - Sets the pipe name to capture audio on "
       "Linux.\n"
 #endif  // BUILDFLAG(IS_LINUX)
@@ -151,7 +151,7 @@ MainRoutineFn SelectMainRoutine(const st
     main_routine = &SingleProcessHostProcessMain;
   } else if (process_type == kProcessTypeNetwork) {
     main_routine = &NetworkProcessMain;
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   } else if (process_type == kProcessTypeDaemon) {
     main_routine = &DaemonProcessMain;
   } else if (process_type == kProcessTypeDesktop) {
@@ -165,7 +165,7 @@ MainRoutineFn SelectMainRoutine(const st
   } else if (process_type == kProcessTypeUrlForwarderConfigurator) {
     main_routine = &UrlForwarderConfiguratorMain;
 #endif  // BUILDFLAG(IS_WIN)
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   } else if (process_type == kProcessTypeXSessionChooser) {
     main_routine = &XSessionChooserMain;
   } else if (process_type == kProcessTypeUserSystemdEnv) {
@@ -235,7 +235,7 @@ int HostMain(int argc, char** argv) {
   // Note that we enable crash reporting only if the user has opted in to having
   // the crash reports uploaded.
   if (IsUsageStatsAllowed()) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     InitializeCrashpadReporting();
 #elif BUILDFLAG(IS_WIN)
     // TODO: joedow - Enable crash reporting for the RDP process.
@@ -279,7 +279,7 @@ int HostMain(int argc, char** argv) {
   // Mac, where the broker process is the agent process broker.
   is_broker_process |= main_routine == &SingleProcessHostProcessMain;
 #endif
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // For multi-process hosts, the daemon process acts as the broker.
   is_broker_process |= main_routine == &DaemonProcessMain;
 #endif
