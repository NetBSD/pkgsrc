$NetBSD: patch-content_browser_browser__child__process__host__impl.cc,v 1.1 2025/02/06 09:58:04 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/browser/browser_child_process_host_impl.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ content/browser/browser_child_process_host_impl.cc
@@ -328,6 +328,7 @@ void BrowserChildProcessHostImpl::Launch
       switches::kLogBestEffortTasks,
       switches::kPerfettoDisableInterning,
       switches::kTraceToConsole,
+      switches::kDisableUnveil,
   };
   cmd_line->CopySwitchesFrom(browser_command_line, kForwardSwitches);
 
@@ -659,7 +660,7 @@ void BrowserChildProcessHostImpl::OnProc
           ->child_process());
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   child_thread_type_switcher_.SetPid(process.Pid());
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
