$NetBSD: patch-src_3rdparty_chromium_services_device_hid_hid__service__netbsd.cc,v 1.2 2026/04/30 06:39:42 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/services/device/hid/hid_service_netbsd.cc.orig	2024-12-21 10:25:10.584948247 +0000
+++ src/3rdparty/chromium/services/device/hid/hid_service_netbsd.cc
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
