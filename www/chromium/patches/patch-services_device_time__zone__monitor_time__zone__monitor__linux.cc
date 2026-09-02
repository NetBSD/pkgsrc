$NetBSD: patch-services_device_time__zone__monitor_time__zone__monitor__linux.cc,v 1.25 2026/09/02 13:13:35 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- services/device/time_zone_monitor/time_zone_monitor_linux.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ services/device/time_zone_monitor/time_zone_monitor_linux.cc
@@ -132,9 +132,12 @@ class TimeZoneMonitorLinuxImpl
     // false positives are harmless, assuming the false positive rate is
     // reasonable.
     const auto kFilesToWatch = std::to_array<const char*>({
-        "/etc/localtime",
+#if BUILDFLAG(IS_BSD)
+        "@PKG_SYSCONFBASE@/localtime",
+#else
         "/etc/timezone",
         "/etc/TZ",
+#endif
     });
     for (size_t index = 0; index < std::size(kFilesToWatch); ++index) {
       file_path_watchers_.push_back(std::make_unique<base::FilePathWatcher>());
