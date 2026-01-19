$NetBSD: patch-services_device_usb_usb__service__fake.cc,v 1.14 2026/01/19 16:14:19 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- services/device/usb/usb_service_fake.cc.orig	2026-01-19 14:53:54.710889786 +0000
+++ services/device/usb/usb_service_fake.cc
@@ -0,0 +1,50 @@
+// Copyright 2014 The Chromium Authors
+// Use of this source code is governed by a BSD-style license that can be
+// found in the LICENSE file.
+
+#include "services/device/usb/usb_service_fake.h"
+
+#include <stdint.h>
+
+#include <list>
+#include <memory>
+#include <set>
+#include <utility>
+
+#include "base/barrier_closure.h"
+#include "base/containers/contains.h"
+#include "base/location.h"
+#include "base/notimplemented.h"
+#include "base/memory/ref_counted_memory.h"
+#include "base/memory/weak_ptr.h"
+#include "base/strings/string_number_conversions.h"
+#include "base/strings/utf_string_conversions.h"
+#include "base/task/sequenced_task_runner.h"
+#include "base/task/single_thread_task_runner.h"
+#include "base/task/thread_pool.h"
+#include "base/threading/scoped_blocking_call.h"
+#include "build/build_config.h"
+#include "components/device_event_log/device_event_log.h"
+#include "services/device/usb/usb_device_handle.h"
+#include "services/device/usb/usb_error.h"
+#include "services/device/usb/webusb_descriptors.h"
+
+namespace device {
+
+UsbServiceImpl::UsbServiceImpl()
+    : task_runner_(base::SequencedTaskRunner::GetCurrentDefault()) {
+  NOTIMPLEMENTED();
+}
+
+UsbServiceImpl::~UsbServiceImpl() {
+  NOTIMPLEMENTED();
+  NotifyWillDestroyUsbService();
+}
+
+void UsbServiceImpl::GetDevices(GetDevicesCallback callback) {
+  NOTIMPLEMENTED();
+  DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
+  UsbService::GetDevices(std::move(callback));
+}
+
+}  // namespace device
