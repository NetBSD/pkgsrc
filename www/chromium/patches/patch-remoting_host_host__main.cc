$NetBSD: patch-remoting_host_host__main.cc,v 1.1 2025/02/06 09:58:18 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/host_main.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ remoting/host/host_main.cc
@@ -50,7 +50,7 @@ int FileChooserMain();
 int RdpDesktopSessionMain();
 int UrlForwarderConfiguratorMain();
 #endif  // BUILDFLAG(IS_WIN)
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 int XSessionChooserMain();
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
@@ -63,7 +63,7 @@ const char kUsageMessage[] =
     "\n"
     "Options:\n"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     "  --audio-pipe-name=<pipe> - Sets the pipe name to capture audio on "
     "Linux.\n"
 #endif  // BUILDFLAG(IS_LINUX)
@@ -156,7 +156,7 @@ MainRoutineFn SelectMainRoutine(const st
   } else if (process_type == kProcessTypeUrlForwarderConfigurator) {
     main_routine = &UrlForwarderConfiguratorMain;
 #endif  // BUILDFLAG(IS_WIN)
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   } else if (process_type == kProcessTypeXSessionChooser) {
     main_routine = &XSessionChooserMain;
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
@@ -222,7 +222,7 @@ int HostMain(int argc, char** argv) {
   // be initialized first, so that the preference for crash-reporting can be
   // looked up in the config file.
   if (IsUsageStatsAllowed()) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     InitializeCrashReporting();
 #elif BUILDFLAG(IS_WIN)
     // TODO: joedow - Enable crash reporting for the RDP process.
