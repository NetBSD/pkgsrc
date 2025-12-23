$NetBSD: patch-services_device_usb_usb__service__fake.h,v 1.13 2025/12/23 13:22:23 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- services/device/usb/usb_service_fake.h.orig	2025-12-22 09:38:34.118525413 +0000
+++ services/device/usb/usb_service_fake.h
@@ -0,0 +1,48 @@
+// Copyright 2015 The Chromium Authors
+// Use of this source code is governed by a BSD-style license that can be
+// found in the LICENSE file.
+
+#ifndef SERVICES_DEVICE_USB_USB_SERVICE_IMPL_H_
+#define SERVICES_DEVICE_USB_USB_SERVICE_IMPL_H_
+
+#include "services/device/usb/usb_service.h"
+
+#include <stddef.h>
+
+#include <map>
+#include <set>
+#include <string>
+#include <vector>
+
+#include "base/containers/queue.h"
+#include "base/memory/weak_ptr.h"
+#include "build/build_config.h"
+#include "services/device/usb/usb_context.h"
+#include "services/device/usb/usb_device_impl.h"
+#include "third_party/abseil-cpp/absl/types/optional.h"
+
+namespace device {
+
+class UsbDeviceImpl;
+
+class UsbServiceImpl final : public UsbService {
+ public:
+  UsbServiceImpl();
+
+  UsbServiceImpl(const UsbServiceImpl&) = delete;
+  UsbServiceImpl& operator=(const UsbServiceImpl&) = delete;
+
+  ~UsbServiceImpl() override;
+
+ private:
+  // device::UsbService implementation
+  void GetDevices(GetDevicesCallback callback) override;
+
+  void OnUsbContext(scoped_refptr<UsbContext> context);
+
+  scoped_refptr<base::SequencedTaskRunner> task_runner_;
+};
+
+}  // namespace device
+
+#endif  // SERVICES_DEVICE_USB_USB_SERVICE_IMPL_H_
