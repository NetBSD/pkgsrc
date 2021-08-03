$NetBSD: patch-src_3rdparty_chromium_services_device_time__zone__monitor_time__zone__monitor__linux.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/services/device/time_zone_monitor/time_zone_monitor_linux.cc.orig	2020-07-15 18:56:01.000000000 +0000
+++ src/3rdparty/chromium/services/device/time_zone_monitor/time_zone_monitor_linux.cc
@@ -127,7 +127,11 @@ class TimeZoneMonitorLinuxImpl
     // false positives are harmless, assuming the false positive rate is
     // reasonable.
     const char* const kFilesToWatch[] = {
+#if defined(OS_BSD)
+        "/etc/localtime",
+#else
         "/etc/localtime", "/etc/timezone", "/etc/TZ",
+#endif
     };
     for (size_t index = 0; index < base::size(kFilesToWatch); ++index) {
       file_path_watchers_.push_back(std::make_unique<base::FilePathWatcher>());
