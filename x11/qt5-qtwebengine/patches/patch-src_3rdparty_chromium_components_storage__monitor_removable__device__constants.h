$NetBSD: patch-src_3rdparty_chromium_components_storage__monitor_removable__device__constants.h,v 1.2 2022/04/18 11:18:18 adam Exp $

--- src/3rdparty/chromium/components/storage_monitor/removable_device_constants.h.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/components/storage_monitor/removable_device_constants.h
@@ -15,7 +15,7 @@ namespace storage_monitor {
 extern const char kFSUniqueIdPrefix[];
 extern const char kVendorModelSerialPrefix[];
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 extern const char kVendorModelVolumeStoragePrefix[];
 #endif
 
