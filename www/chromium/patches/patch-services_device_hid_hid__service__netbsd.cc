$NetBSD: patch-services_device_hid_hid__service__netbsd.cc,v 1.13 2025/12/23 13:22:22 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- services/device/hid/hid_service_netbsd.cc.orig	2025-12-22 09:38:34.116614523 +0000
+++ services/device/hid/hid_service_netbsd.cc
@@ -0,0 +1,27 @@
+// Copyright 2022 The Chromium Authors
+// Use of this source code is governed by a BSD-style license that can be
+// found in the LICENSE file.
+
+#include "services/device/hid/hid_service_netbsd.h"
+
+#include "base/notimplemented.h"
+#include "services/device/hid/hid_connection.h"
+
+namespace device {
+
+HidServiceNetBSD::HidServiceNetBSD() = default;
+HidServiceNetBSD::~HidServiceNetBSD() = default;
+
+void HidServiceNetBSD::Connect(const std::string& device_id,
+                                bool allow_protected_reports,
+                                bool allow_fido_reports,
+                                ConnectCallback callback) {
+  NOTIMPLEMENTED_LOG_ONCE();
+  std::move(callback).Run(nullptr);
+}
+
+base::WeakPtr<HidService> HidServiceNetBSD::GetWeakPtr() {
+  return weak_factory_.GetWeakPtr();
+}
+
+}  // namespace device
