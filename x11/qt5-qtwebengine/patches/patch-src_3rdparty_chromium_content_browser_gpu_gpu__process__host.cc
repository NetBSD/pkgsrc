$NetBSD: patch-src_3rdparty_chromium_content_browser_gpu_gpu__process__host.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/content/browser/gpu/gpu_process_host.cc.orig	2020-07-08 21:41:48.000000000 +0000
+++ src/3rdparty/chromium/content/browser/gpu/gpu_process_host.cc
@@ -1117,7 +1117,7 @@ bool GpuProcessHost::LaunchGpuProcess() 
   std::unique_ptr<base::CommandLine> cmd_line =
       std::make_unique<base::CommandLine>(base::CommandLine::NO_PROGRAM);
 #else
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   int child_flags = gpu_launcher.empty() ? ChildProcessHost::CHILD_ALLOW_SELF
                                          : ChildProcessHost::CHILD_NORMAL;
 #elif defined(OS_MACOSX)
