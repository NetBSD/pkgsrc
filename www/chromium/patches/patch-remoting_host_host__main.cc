$NetBSD: patch-remoting_host_host__main.cc,v 1.14 2026/01/19 16:14:18 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- remoting/host/host_main.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ remoting/host/host_main.cc
@@ -53,7 +53,7 @@ int FileChooserMain();
 int RdpDesktopSessionMain();
 int UrlForwarderConfiguratorMain();
 #endif  // BUILDFLAG(IS_WIN)
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 int XSessionChooserMain();
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
@@ -67,7 +67,7 @@ void Usage(const base::FilePath& program
       "\n"
       "Options:\n"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       "  --audio-pipe-name=<pipe> - Sets the pipe name to capture audio on "
       "Linux.\n"
 #endif  // BUILDFLAG(IS_LINUX)
@@ -157,7 +157,7 @@ MainRoutineFn SelectMainRoutine(const st
   } else if (process_type == kProcessTypeUrlForwarderConfigurator) {
     main_routine = &UrlForwarderConfiguratorMain;
 #endif  // BUILDFLAG(IS_WIN)
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   } else if (process_type == kProcessTypeXSessionChooser) {
     main_routine = &XSessionChooserMain;
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
@@ -225,7 +225,7 @@ int HostMain(int argc, char** argv) {
   // Note that we enable crash reporting only if the user has opted in to having
   // the crash reports uploaded.
   if (IsUsageStatsAllowed()) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     InitializeCrashpadReporting();
 #elif BUILDFLAG(IS_WIN)
     // TODO: joedow - Enable crash reporting for the RDP process.
