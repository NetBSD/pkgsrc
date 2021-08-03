$NetBSD: patch-src_3rdparty_chromium_ui_events_devices_x11_device__data__manager__x11.cc,v 1.1 2021/08/03 21:04:36 markd Exp $

--- src/3rdparty/chromium/ui/events/devices/x11/device_data_manager_x11.cc.orig	2020-07-15 18:56:34.000000000 +0000
+++ src/3rdparty/chromium/ui/events/devices/x11/device_data_manager_x11.cc
@@ -875,6 +875,7 @@ void DeviceDataManagerX11::SetDisabledKe
 }
 
 void DeviceDataManagerX11::DisableDevice(int deviceid) {
+#if !defined(OS_BSD)
   blocked_devices_.set(deviceid, true);
   // TODO(rsadam@): Support blocking touchscreen devices.
   std::vector<InputDevice> keyboards = GetKeyboardDevices();
@@ -885,6 +886,9 @@ void DeviceDataManagerX11::DisableDevice
     keyboards.erase(it);
     DeviceDataManager::OnKeyboardDevicesUpdated(keyboards);
   }
+#else
+  NOTIMPLEMENTED();
+#endif
 }
 
 void DeviceDataManagerX11::EnableDevice(int deviceid) {
