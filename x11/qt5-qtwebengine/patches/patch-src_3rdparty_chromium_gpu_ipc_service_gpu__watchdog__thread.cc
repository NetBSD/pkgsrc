$NetBSD: patch-src_3rdparty_chromium_gpu_ipc_service_gpu__watchdog__thread.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/gpu/ipc/service/gpu_watchdog_thread.cc.orig	2020-11-07 01:22:36.000000000 +0000
+++ src/3rdparty/chromium/gpu/ipc/service/gpu_watchdog_thread.cc
@@ -64,7 +64,7 @@ void GpuWatchdogTimeoutHistogram(GpuWatc
   base::UmaHistogramEnumeration("GPU.WatchdogThread.V1.Timeout", timeout_event);
 }
 
-#if defined(USE_X11)
+#if defined(USE_X11) && !defined(OS_BSD)
 const base::FilePath::CharType kTtyFilePath[] =
     FILE_PATH_LITERAL("/sys/class/tty/tty0/active");
 #endif
@@ -82,7 +82,7 @@ GpuWatchdogThreadImplV1::GpuWatchdogThre
       arm_cpu_time_(),
 #endif
       suspension_counter_(this)
-#if defined(USE_X11)
+#if defined(USE_X11) && !defined(OS_BSD)
       ,
       host_tty_(-1)
 #endif
@@ -104,7 +104,7 @@ GpuWatchdogThreadImplV1::GpuWatchdogThre
   DCHECK(result);
 #endif
 
-#if defined(USE_X11)
+#if defined(USE_X11) && !defined(OS_BSD)
   tty_file_ = base::OpenFile(base::FilePath(kTtyFilePath), "r");
   UpdateActiveTTY();
   host_tty_ = active_tty_;
@@ -252,7 +252,7 @@ GpuWatchdogThreadImplV1::~GpuWatchdogThr
 
   base::PowerMonitor::RemoveObserver(this);
 
-#if defined(USE_X11)
+#if defined(USE_X11) && !defined(OS_BSD)
   if (tty_file_)
     fclose(tty_file_);
 #endif
@@ -435,7 +435,7 @@ void GpuWatchdogThreadImplV1::Deliberate
     return;
 #endif
 
-#if defined(USE_X11)
+#if defined(USE_X11) && !defined(OS_BSD)
   // Don't crash if we're not on the TTY of our host X11 server.
   UpdateActiveTTY();
   if (host_tty_ != -1 && active_tty_ != -1 && host_tty_ != active_tty_) {
@@ -610,7 +610,7 @@ base::ThreadTicks GpuWatchdogThreadImplV
 }
 #endif
 
-#if defined(USE_X11)
+#if defined(USE_X11) && !defined(OS_BSD)
 void GpuWatchdogThreadImplV1::UpdateActiveTTY() {
   last_active_tty_ = active_tty_;
 
