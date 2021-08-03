$NetBSD: patch-src_3rdparty_chromium_gpu_ipc_service_gpu__watchdog__thread.h,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/gpu/ipc/service/gpu_watchdog_thread.h.orig	2020-11-07 01:22:36.000000000 +0000
+++ src/3rdparty/chromium/gpu/ipc/service/gpu_watchdog_thread.h
@@ -213,7 +213,7 @@ class GPU_IPC_SERVICE_EXPORT GpuWatchdog
   base::ThreadTicks GetWatchedThreadTime();
 #endif
 
-#if defined(USE_X11)
+#if defined(USE_X11) && !defined(OS_BSD)
   void UpdateActiveTTY();
 #endif
 
@@ -271,7 +271,7 @@ class GPU_IPC_SERVICE_EXPORT GpuWatchdog
   // whether GpuWatchdogThreadEvent::kGpuWatchdogStart has been recorded.
   bool is_watchdog_start_histogram_recorded = false;
 
-#if defined(USE_X11)
+#if defined(USE_X11) && !defined(OS_BSD)
   FILE* tty_file_;
   int host_tty_;
   int active_tty_ = -1;
