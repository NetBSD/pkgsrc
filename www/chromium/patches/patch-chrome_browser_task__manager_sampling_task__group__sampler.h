$NetBSD: patch-chrome_browser_task__manager_sampling_task__group__sampler.h,v 1.1 2025/02/06 09:57:51 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/task_manager/sampling/task_group_sampler.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ chrome/browser/task_manager/sampling/task_group_sampler.h
@@ -31,7 +31,7 @@ class TaskGroupSampler : public base::Re
   using OnCpuRefreshCallback = base::RepeatingCallback<void(double)>;
   using OnSwappedMemRefreshCallback = base::RepeatingCallback<void(int64_t)>;
   using OnIdleWakeupsCallback = base::RepeatingCallback<void(int)>;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   using OnOpenFdCountCallback = base::RepeatingCallback<void(int)>;
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
   using OnProcessPriorityCallback =
@@ -43,7 +43,7 @@ class TaskGroupSampler : public base::Re
       const OnCpuRefreshCallback& on_cpu_refresh,
       const OnSwappedMemRefreshCallback& on_memory_refresh,
       const OnIdleWakeupsCallback& on_idle_wakeups,
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
       const OnOpenFdCountCallback& on_open_fd_count,
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
       const OnProcessPriorityCallback& on_process_priority);
@@ -63,7 +63,7 @@ class TaskGroupSampler : public base::Re
   double RefreshCpuUsage();
   int64_t RefreshSwappedMem();
   int RefreshIdleWakeupsPerSecond();
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   int RefreshOpenFdCount();
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
   base::Process::Priority RefreshProcessPriority();
@@ -87,7 +87,7 @@ class TaskGroupSampler : public base::Re
   const OnCpuRefreshCallback on_cpu_refresh_callback_;
   const OnSwappedMemRefreshCallback on_swapped_mem_refresh_callback_;
   const OnIdleWakeupsCallback on_idle_wakeups_callback_;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   const OnOpenFdCountCallback on_open_fd_count_callback_;
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
   const OnProcessPriorityCallback on_process_priority_callback_;
