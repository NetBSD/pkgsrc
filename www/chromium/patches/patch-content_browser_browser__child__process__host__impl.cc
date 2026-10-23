$NetBSD: patch-content_browser_browser__child__process__host__impl.cc,v 1.31 2026/10/23 15:05:26 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/browser/browser_child_process_host_impl.cc.orig	2026-10-19 20:07:21.000000000 +0000
+++ content/browser/browser_child_process_host_impl.cc
@@ -308,6 +308,7 @@ void BrowserChildProcessHostImpl::Launch
       switches::kLogBestEffortTasks,
       switches::kPartitionAllocSchedulerLoopQuarantine,
       switches::kPerfettoDisableInterning,
+      switches::kDisableUnveil,
   };
   cmd_line->CopySwitchesFrom(browser_command_line, kForwardSwitches);
 
@@ -662,7 +663,7 @@ void BrowserChildProcessHostImpl::OnProc
           ->child_process());
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   child_thread_type_switcher_.SetPid(process.Pid());
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
