$NetBSD: patch-src_3rdparty_chromium_ui_events_devices_x11_device__data__manager__x11.cc,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/ui/events/devices/x11/device_data_manager_x11.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/ui/events/devices/x11/device_data_manager_x11.cc
@@ -841,6 +841,7 @@ void DeviceDataManagerX11::SetDisabledKe
 }
 
 void DeviceDataManagerX11::DisableDevice(x11::Input::DeviceId deviceid) {
+#if !defined(OS_BSD)
   blocked_devices_.set(static_cast<uint32_t>(deviceid), true);
   // TODO(rsadam@): Support blocking touchscreen devices.
   std::vector<InputDevice> keyboards = GetKeyboardDevices();
@@ -850,6 +851,9 @@ void DeviceDataManagerX11::DisableDevice
     keyboards.erase(it);
     DeviceDataManager::OnKeyboardDevicesUpdated(keyboards);
   }
+#else
+  NOTIMPLEMENTED();
+#endif
 }
 
 void DeviceDataManagerX11::EnableDevice(x11::Input::DeviceId deviceid) {
