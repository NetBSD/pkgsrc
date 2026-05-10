$NetBSD: patch-components_sync__device__info_local__device__info__util.cc,v 1.19 2026/05/10 15:29:56 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/sync_device_info/local_device_info_util.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ components/sync_device_info/local_device_info_util.cc
@@ -84,7 +84,7 @@ void OnMachineStatisticsLoaded(LocalDevi
 DeviceInfo::DeviceType GetLocalDeviceType() {
 #if BUILDFLAG(IS_CHROMEOS)
   return DeviceInfo::DeviceType::kChromeOS;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return DeviceInfo::DeviceType::kLinux;
 #elif BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_IOS)
   switch (ui::GetDeviceFormFactor()) {
@@ -107,7 +107,7 @@ DeviceInfo::DeviceType GetLocalDeviceTyp
 DeviceInfo::OsType GetLocalDeviceOSType() {
 #if BUILDFLAG(IS_CHROMEOS)
   return DeviceInfo::OsType::kChromeOsAsh;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return DeviceInfo::OsType::kLinux;
 #elif BUILDFLAG(IS_ANDROID)
   return DeviceInfo::OsType::kAndroid;
