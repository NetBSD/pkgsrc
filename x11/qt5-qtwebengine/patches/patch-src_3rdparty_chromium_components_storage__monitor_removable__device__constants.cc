$NetBSD: patch-src_3rdparty_chromium_components_storage__monitor_removable__device__constants.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/components/storage_monitor/removable_device_constants.cc.orig	2020-07-08 21:40:41.000000000 +0000
+++ src/3rdparty/chromium/components/storage_monitor/removable_device_constants.cc
@@ -10,7 +10,7 @@ namespace storage_monitor {
 const char kFSUniqueIdPrefix[] = "UUID:";
 const char kVendorModelSerialPrefix[] = "VendorModelSerial:";
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 const char kVendorModelVolumeStoragePrefix[] = "VendorModelVolumeStorage:";
 #endif
 
