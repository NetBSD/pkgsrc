$NetBSD: patch-src_3rdparty_chromium_components_metrics_metrics__log.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/components/metrics/metrics_log.cc.orig	2020-07-08 21:41:47.000000000 +0000
+++ src/3rdparty/chromium/components/metrics/metrics_log.cc
@@ -215,7 +215,7 @@ void MetricsLog::RecordCoreSystemProfile
 // OperatingSystemVersion refers to the ChromeOS release version.
 #if defined(OS_CHROMEOS)
   os->set_kernel_version(base::SysInfo::KernelVersion());
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   // Linux operating system version is copied over into kernel version to be
   // consistent.
   os->set_kernel_version(base::SysInfo::OperatingSystemVersion());
