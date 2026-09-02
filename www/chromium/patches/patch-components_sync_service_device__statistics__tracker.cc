$NetBSD: patch-components_sync_service_device__statistics__tracker.cc,v 1.7 2026/09/02 13:13:30 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/sync/service/device_statistics_tracker.cc.orig	2026-08-31 22:47:51.000000000 +0000
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
