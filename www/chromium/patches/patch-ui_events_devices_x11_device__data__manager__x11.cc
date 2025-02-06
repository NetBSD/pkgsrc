$NetBSD: patch-ui_events_devices_x11_device__data__manager__x11.cc,v 1.1 2025/02/06 09:58:31 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/events/devices/x11/device_data_manager_x11.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ ui/events/devices/x11/device_data_manager_x11.cc
@@ -849,6 +849,7 @@ void DeviceDataManagerX11::SetDisabledKe
 }
 
 void DeviceDataManagerX11::DisableDevice(x11::Input::DeviceId deviceid) {
+  NOTIMPLEMENTED();
   blocked_devices_.set(static_cast<uint32_t>(deviceid), true);
   // TODO(rsadam@): Support blocking touchscreen devices.
   std::vector<KeyboardDevice> keyboards = GetKeyboardDevices();
