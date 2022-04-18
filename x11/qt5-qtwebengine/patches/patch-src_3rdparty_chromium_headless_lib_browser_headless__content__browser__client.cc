$NetBSD: patch-src_3rdparty_chromium_headless_lib_browser_headless__content__browser__client.cc,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/headless/lib/browser/headless_content_browser_client.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/headless/lib/browser/headless_content_browser_client.cc
@@ -158,7 +158,7 @@ HeadlessContentBrowserClient::GetGenerat
   return content::GeneratedCodeCacheSettings(true, 0, context->GetPath());
 }
 
-#if defined(OS_POSIX) && !defined(OS_MAC)
+#if defined(OS_POSIX) && !defined(OS_MAC) && !defined(OS_BSD)
 void HeadlessContentBrowserClient::GetAdditionalMappedFilesForChildProcess(
     const base::CommandLine& command_line,
     int child_process_id,
@@ -241,7 +241,7 @@ void HeadlessContentBrowserClient::Appen
                                             process_type, child_process_id);
   }
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // Processes may only query perf_event_open with the BPF sandbox disabled.
   if (old_command_line.HasSwitch(::switches::kEnableThreadInstructionCount) &&
       old_command_line.HasSwitch(sandbox::policy::switches::kNoSandbox)) {
