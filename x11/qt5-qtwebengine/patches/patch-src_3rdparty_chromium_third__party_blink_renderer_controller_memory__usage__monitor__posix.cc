$NetBSD: patch-src_3rdparty_chromium_third__party_blink_renderer_controller_memory__usage__monitor__posix.cc,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/third_party/blink/renderer/controller/memory_usage_monitor_posix.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/third_party/blink/renderer/controller/memory_usage_monitor_posix.cc
@@ -134,7 +134,7 @@ void MemoryUsageMonitorPosix::SetProcFil
   status_fd_.reset(status_file.TakePlatformFile());
 }
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 // static
 void MemoryUsageMonitorPosix::Bind(
     mojo::PendingReceiver<mojom::blink::MemoryUsageMonitorLinux> receiver) {
