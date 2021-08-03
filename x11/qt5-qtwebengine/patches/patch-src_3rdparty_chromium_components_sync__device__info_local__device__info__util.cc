$NetBSD: patch-src_3rdparty_chromium_components_sync__device__info_local__device__info__util.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/components/sync_device_info/local_device_info_util.cc.orig	2020-07-08 21:40:41.000000000 +0000
+++ src/3rdparty/chromium/components/sync_device_info/local_device_info_util.cc
@@ -19,7 +19,7 @@ std::string GetPersonalizableDeviceNameI
 sync_pb::SyncEnums::DeviceType GetLocalDeviceType() {
 #if defined(OS_CHROMEOS)
   return sync_pb::SyncEnums_DeviceType_TYPE_CROS;
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   return sync_pb::SyncEnums_DeviceType_TYPE_LINUX;
 #elif defined(OS_ANDROID) || defined(OS_IOS)
   return ui::GetDeviceFormFactor() == ui::DEVICE_FORM_FACTOR_TABLET
