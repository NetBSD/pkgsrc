$NetBSD: patch-src_3rdparty_chromium_components_storage__monitor_removable__device__constants.h,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/components/storage_monitor/removable_device_constants.h.orig	2020-07-08 21:40:41.000000000 +0000
+++ src/3rdparty/chromium/components/storage_monitor/removable_device_constants.h
@@ -15,7 +15,7 @@ namespace storage_monitor {
 extern const char kFSUniqueIdPrefix[];
 extern const char kVendorModelSerialPrefix[];
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 extern const char kVendorModelVolumeStoragePrefix[];
 #endif
 
