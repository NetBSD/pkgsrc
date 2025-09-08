$NetBSD: patch-content_browser_browser__child__process__host__impl.cc,v 1.6 2025/09/08 13:24:25 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/browser/browser_child_process_host_impl.cc.orig	2025-08-29 18:50:09.000000000 +0000
+++ content/browser/browser_child_process_host_impl.cc
@@ -297,6 +297,7 @@ void BrowserChildProcessHostImpl::Launch
       switches::kLogBestEffortTasks,
       switches::kPerfettoDisableInterning,
       switches::kTraceToConsole,
+      switches::kDisableUnveil,
   };
   cmd_line->CopySwitchesFrom(browser_command_line, kForwardSwitches);
 
@@ -650,7 +651,7 @@ void BrowserChildProcessHostImpl::OnProc
           ->child_process());
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   child_thread_type_switcher_.SetPid(process.Pid());
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
