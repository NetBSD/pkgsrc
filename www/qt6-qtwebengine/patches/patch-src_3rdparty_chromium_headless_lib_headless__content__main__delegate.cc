$NetBSD: patch-src_3rdparty_chromium_headless_lib_headless__content__main__delegate.cc,v 1.1 2025/12/21 09:38:31 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/headless/lib/headless_content_main_delegate.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/headless/lib/headless_content_main_delegate.cc
@@ -407,7 +407,7 @@ void HeadlessContentMainDelegate::InitCr
   if (process_type != ::switches::kZygoteProcess) {
     g_headless_crash_client.Pointer()->set_crash_dumps_dir(
         command_line.GetSwitchValuePath(switches::kCrashDumpsDir));
-#if !BUILDFLAG(IS_WIN)
+#if !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_BSD)
     crash_reporter::InitializeCrashpad(process_type.empty(), process_type);
 #endif  // !BUILDFLAG(IS_WIN)
     crash_keys::SetSwitchesFromCommandLine(command_line, nullptr);
