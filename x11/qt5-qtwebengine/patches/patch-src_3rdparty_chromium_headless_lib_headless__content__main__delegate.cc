$NetBSD: patch-src_3rdparty_chromium_headless_lib_headless__content__main__delegate.cc,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/headless/lib/headless_content_main_delegate.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/headless/lib/headless_content_main_delegate.cc
@@ -323,7 +323,7 @@ void HeadlessContentMainDelegate::InitCr
     const base::CommandLine& command_line) {
   if (command_line.HasSwitch(::switches::kDisableBreakpad))
     return;
-#if defined(OS_FUCHSIA)
+#if defined(OS_FUCHSIA) || defined(OS_BSD)
   // TODO(fuchsia): Implement this when crash reporting/Breakpad are available
   // in Fuchsia. (crbug.com/753619)
   NOTIMPLEMENTED();
@@ -404,7 +404,7 @@ int HeadlessContentMainDelegate::RunProc
   return 0;
 }
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 void SIGTERMProfilingShutdown(int signal) {
   content::Profiling::Stop();
   struct sigaction sigact;
