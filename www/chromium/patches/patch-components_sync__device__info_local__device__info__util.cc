$NetBSD: patch-components_sync__device__info_local__device__info__util.cc,v 1.25 2026/09/02 13:13:30 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/sync_device_info/local_device_info_util.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ components/sync_device_info/local_device_info_util.cc
@@ -91,7 +91,7 @@ void OnMachineStatisticsLoaded(LocalDevi
 DeviceInfo::DeviceType GetLocalDeviceType() {
 #if BUILDFLAG(IS_CHROMEOS)
   return DeviceInfo::DeviceType::kChromeOS;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return DeviceInfo::DeviceType::kLinux;
 #elif BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_IOS)
   switch (ui::GetDeviceFormFactor()) {
@@ -114,7 +114,7 @@ DeviceInfo::DeviceType GetLocalDeviceTyp
 DeviceInfo::OsType GetLocalDeviceOSType() {
 #if BUILDFLAG(IS_CHROMEOS)
   return DeviceInfo::OsType::kChromeOsAsh;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return DeviceInfo::OsType::kLinux;
 #elif BUILDFLAG(IS_ANDROID)
   return DeviceInfo::OsType::kAndroid;
