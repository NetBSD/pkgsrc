$NetBSD: patch-src_3rdparty_chromium_services_device_hid_hid__connection__netbsd.h,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/services/device/hid/hid_connection_netbsd.h.orig	2020-07-23 00:19:44.670620204 +0000
+++ src/3rdparty/chromium/services/device/hid/hid_connection_netbsd.h
@@ -0,0 +1,68 @@
+// Copyright (c) 2014 The Chromium Authors. All rights reserved.
+// Use of this source code is governed by a BSD-style license that can be
+// found in the LICENSE file.
+
+#ifndef DEVICE_HID_HID_CONNECTION_NETBSD_H_
+#define DEVICE_HID_HID_CONNECTION_NETBSD_H_
+
+#include <stddef.h>
+#include <stdint.h>
+
+#include "base/files/scoped_file.h"
+#include "base/macros.h"
+#include "base/memory/ptr_util.h"
+#include "base/memory/ref_counted_memory.h"
+#include "base/memory/weak_ptr.h"
+#include "base/sequence_checker.h"
+#include "services/device/hid/hid_connection.h"
+
+namespace base {
+class SequencedTaskRunner;
+}
+
+namespace net {
+class IOBuffer;
+}
+
+namespace device {
+
+class HidConnectionNetBSD : public HidConnection {
+ public:
+  HidConnectionNetBSD(
+      scoped_refptr<HidDeviceInfo> device_info,
+      base::ScopedFD fd,
+      scoped_refptr<base::SequencedTaskRunner> blocking_task_runner);
+
+ private:
+  friend class base::RefCountedThreadSafe<HidConnectionNetBSD>;
+  class BlockingTaskHelper;
+
+  ~HidConnectionNetBSD() override;
+
+  // HidConnection implementation.
+  void PlatformClose() override;
+  void PlatformWrite(scoped_refptr<base::RefCountedBytes> buffer,
+                     WriteCallback callback) override;
+  void PlatformGetFeatureReport(uint8_t report_id,
+                                ReadCallback callback) override;
+  void PlatformSendFeatureReport(scoped_refptr<base::RefCountedBytes> buffer,
+                                 WriteCallback callback) override;
+
+  // |helper_| lives on the sequence to which |blocking_task_runner_| posts
+  // tasks so all calls must be posted there including this object's
+  // destruction.
+  std::unique_ptr<BlockingTaskHelper> helper_;
+
+  const scoped_refptr<base::SequencedTaskRunner> blocking_task_runner_;
+  const scoped_refptr<base::SequencedTaskRunner> task_runner_;
+
+  SEQUENCE_CHECKER(sequence_checker_);
+
+  base::WeakPtrFactory<HidConnectionNetBSD> weak_factory_;
+
+  DISALLOW_COPY_AND_ASSIGN(HidConnectionNetBSD);
+};
+
+}  // namespace device
+
+#endif  // DEVICE_HID_HID_CONNECTION_NETBSD_H_
