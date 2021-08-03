$NetBSD: patch-src_3rdparty_chromium_services_device_hid_hid__service__netbsd.h,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/services/device/hid/hid_service_netbsd.h.orig	2020-07-23 00:21:18.942556354 +0000
+++ src/3rdparty/chromium/services/device/hid/hid_service_netbsd.h
@@ -0,0 +1,47 @@
+// Copyright 2014 The Chromium Authors. All rights reserved.
+// Use of this source code is governed by a BSD-style license that can be
+// found in the LICENSE file.
+
+#ifndef DEVICE_HID_HID_SERVICE_NETBSD_H_
+#define DEVICE_HID_HID_SERVICE_NETBSD_H_
+
+#include <string>
+
+#include "base/macros.h"
+#include "base/memory/ref_counted.h"
+#include "base/memory/weak_ptr.h"
+#include "base/timer/timer.h"
+#include "services/device/hid/hid_service.h"
+#include "net/base/io_buffer.h"
+
+namespace device {
+
+class HidServiceNetBSD : public HidService {
+ public:
+  HidServiceNetBSD();
+  ~HidServiceNetBSD() override;
+
+  void Connect(const std::string& device_guid,
+               ConnectCallback connect) override;
+  base::WeakPtr<HidService> GetWeakPtr() override;
+
+ private:
+  struct ConnectParams;
+  class BlockingTaskHelper;
+
+  static void OpenOnBlockingThread(std::unique_ptr<ConnectParams> params);
+  static void FinishOpen(std::unique_ptr<ConnectParams> params);
+
+  const scoped_refptr<base::SequencedTaskRunner> task_runner_;
+  const scoped_refptr<base::SequencedTaskRunner> blocking_task_runner_;
+  // |helper_| lives on the sequence |blocking_task_runner_| posts to and holds
+  // a weak reference back to the service that owns it.
+  std::unique_ptr<BlockingTaskHelper> helper_;
+  base::WeakPtrFactory<HidServiceNetBSD> weak_factory_;
+
+  DISALLOW_COPY_AND_ASSIGN(HidServiceNetBSD);
+};
+
+}  // namespace device
+
+#endif  // DEVICE_HID_HID_SERVICE_NETBSD_H_
