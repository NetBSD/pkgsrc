$NetBSD: patch-content_browser_utility__process__host.h,v 1.1 2025/02/06 09:58:06 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/browser/utility_process_host.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ content/browser/utility_process_host.h
@@ -34,7 +34,7 @@ class Thread;
 }  // namespace base
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS_ASH) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 namespace viz {
 class GpuClient;
 }  // namespace viz
@@ -202,7 +202,7 @@ class CONTENT_EXPORT UtilityProcessHost
   LaunchState launch_state_ = LaunchState::kLaunchInProgress;
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS_ASH) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   bool allowed_gpu_;
   std::unique_ptr<viz::GpuClient, base::OnTaskRunnerDeleter> gpu_client_;
 #endif
