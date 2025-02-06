$NetBSD: patch-services_device_hid_hid__service__netbsd.h,v 1.1 2025/02/06 09:58:20 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- services/device/hid/hid_service_netbsd.h.orig	2024-12-21 10:25:10.585482674 +0000
+++ services/device/hid/hid_service_netbsd.h
@@ -0,0 +1,33 @@
+// Copyright 2022 The Chromium Authors
+// Use of this source code is governed by a BSD-style license that can be
+// found in the LICENSE file.
+
+#ifndef SERVICES_DEVICE_HID_HID_SERVICE_NETBSD_H_
+#define SERVICES_DEVICE_HID_HID_SERVICE_NETBSD_H_
+
+#include "services/device/hid/hid_service.h"
+
+namespace device {
+
+class HidServiceNetBSD : public HidService {
+ public:
+  HidServiceNetBSD();
+  ~HidServiceNetBSD() override;
+
+  HidServiceNetBSD(const HidServiceNetBSD&) = delete;
+  HidServiceNetBSD& operator=(const HidServiceNetBSD&) = delete;
+
+ private:
+  // HidService implementation.
+  void Connect(const std::string& device_id,
+               bool allow_protected_reports,
+               bool allow_fido_reports,
+               ConnectCallback callback) override;
+  base::WeakPtr<HidService> GetWeakPtr() override;
+
+  base::WeakPtrFactory<HidServiceNetBSD> weak_factory_{this};
+};
+
+}  // namespace device
+
+#endif  // SERVICES_DEVICE_HID_HID_SERVICE_NETBSD_H_
