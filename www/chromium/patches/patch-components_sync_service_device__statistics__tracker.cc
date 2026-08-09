$NetBSD: patch-components_sync_service_device__statistics__tracker.cc,v 1.6 2026/08/09 06:31:16 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/sync/service/device_statistics_tracker.cc.orig	2026-08-05 20:17:42.000000000 +0000
+++ components/sync/service/device_statistics_tracker.cc
@@ -139,7 +139,7 @@ std::optional<DeviceStatisticsTracker::P
   return DeviceStatisticsTracker::Platform::kWindows;
 #elif BUILDFLAG(IS_MAC)
   return DeviceStatisticsTracker::Platform::kMac;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return DeviceStatisticsTracker::Platform::kLinux;
 #elif BUILDFLAG(IS_CHROMEOS)
   return DeviceStatisticsTracker::Platform::kChromeOS;
