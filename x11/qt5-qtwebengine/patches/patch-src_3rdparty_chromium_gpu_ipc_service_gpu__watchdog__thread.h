$NetBSD: patch-src_3rdparty_chromium_gpu_ipc_service_gpu__watchdog__thread.h,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/gpu/ipc/service/gpu_watchdog_thread.h.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/gpu/ipc/service/gpu_watchdog_thread.h
@@ -213,7 +213,7 @@ class GPU_IPC_SERVICE_EXPORT GpuWatchdog
   base::ThreadTicks GetWatchedThreadTime();
 #endif
 
-#if defined(USE_X11)
+#if defined(USE_X11) && !defined(OS_BSD)
   void UpdateActiveTTY();
 #endif
 
@@ -261,7 +261,7 @@ class GPU_IPC_SERVICE_EXPORT GpuWatchdog
   base::Time check_time_;
   base::TimeTicks check_timeticks_;
 
-#if defined(USE_X11)
+#if defined(USE_X11) && !defined(OS_BSD)
   FILE* tty_file_;
   int host_tty_;
   int active_tty_ = -1;
