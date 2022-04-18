$NetBSD: patch-src_3rdparty_chromium_gpu_ipc_service_gpu__watchdog__thread.cc,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/gpu/ipc/service/gpu_watchdog_thread.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/gpu/ipc/service/gpu_watchdog_thread.cc
@@ -57,7 +57,7 @@ const int kNewGpuTimeout = 17000;
 const int kNewGpuTimeout = 15000;
 #endif
 
-#if defined(USE_X11)
+#if defined(USE_X11) && !defined(OS_BSD)
 const base::FilePath::CharType kTtyFilePath[] =
     FILE_PATH_LITERAL("/sys/class/tty/tty0/active");
 #endif
@@ -75,7 +75,7 @@ GpuWatchdogThreadImplV1::GpuWatchdogThre
       arm_cpu_time_(),
 #endif
       suspension_counter_(this)
-#if defined(USE_X11)
+#if defined(USE_X11) && !defined(OS_BSD)
       ,
       host_tty_(-1)
 #endif
@@ -97,7 +97,7 @@ GpuWatchdogThreadImplV1::GpuWatchdogThre
   DCHECK(result);
 #endif
 
-#if defined(USE_X11)
+#if defined(USE_X11) && !defined(OS_BSD)
   tty_file_ = base::OpenFile(base::FilePath(kTtyFilePath), "r");
   UpdateActiveTTY();
   host_tty_ = active_tty_;
@@ -239,7 +239,7 @@ GpuWatchdogThreadImplV1::~GpuWatchdogThr
 
   base::PowerMonitor::RemoveObserver(this);
 
-#if defined(USE_X11)
+#if defined(USE_X11) && !defined(OS_BSD)
   if (tty_file_)
     fclose(tty_file_);
 #endif
@@ -388,7 +388,7 @@ void GpuWatchdogThreadImplV1::Deliberate
     return;
 #endif
 
-#if defined(USE_X11)
+#if defined(USE_X11) && !defined(OS_BSD)
   // Don't crash if we're not on the TTY of our host X11 server.
   UpdateActiveTTY();
   if (host_tty_ != -1 && active_tty_ != -1 && host_tty_ != active_tty_) {
@@ -548,7 +548,7 @@ base::ThreadTicks GpuWatchdogThreadImplV
 }
 #endif
 
-#if defined(USE_X11)
+#if defined(USE_X11) && !defined(OS_BSD)
 void GpuWatchdogThreadImplV1::UpdateActiveTTY() {
   last_active_tty_ = active_tty_;
 
