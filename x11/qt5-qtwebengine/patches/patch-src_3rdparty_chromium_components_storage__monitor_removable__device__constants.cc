$NetBSD: patch-src_3rdparty_chromium_components_storage__monitor_removable__device__constants.cc,v 1.2 2022/04/18 11:18:18 adam Exp $

--- src/3rdparty/chromium/components/storage_monitor/removable_device_constants.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/components/storage_monitor/removable_device_constants.cc
@@ -10,7 +10,7 @@ namespace storage_monitor {
 const char kFSUniqueIdPrefix[] = "UUID:";
 const char kVendorModelSerialPrefix[] = "VendorModelSerial:";
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 const char kVendorModelVolumeStoragePrefix[] = "VendorModelVolumeStorage:";
 #endif
 
