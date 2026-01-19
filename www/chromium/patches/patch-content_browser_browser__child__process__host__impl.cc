$NetBSD: patch-content_browser_browser__child__process__host__impl.cc,v 1.14 2026/01/19 16:14:14 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/browser/browser_child_process_host_impl.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ content/browser/browser_child_process_host_impl.cc
@@ -291,6 +291,7 @@ void BrowserChildProcessHostImpl::Launch
       switches::kIPCConnectionTimeout,
       switches::kLogBestEffortTasks,
       switches::kPerfettoDisableInterning,
+      switches::kDisableUnveil,
   };
   cmd_line->CopySwitchesFrom(browser_command_line, kForwardSwitches);
 
@@ -648,7 +649,7 @@ void BrowserChildProcessHostImpl::OnProc
           ->child_process());
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   child_thread_type_switcher_.SetPid(process.Pid());
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
