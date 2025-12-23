$NetBSD: patch-base_system_sys__info__netbsd.cc,v 1.13 2025/12/23 13:22:11 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/system/sys_info_netbsd.cc.orig	2025-12-22 09:38:33.949492254 +0000
+++ base/system/sys_info_netbsd.cc
@@ -0,0 +1,99 @@
+// Copyright 2011 The Chromium Authors
+// Use of this source code is governed by a BSD-style license that can be
+// found in the LICENSE file.
+
+#include "base/system/sys_info.h"
+
+#include <stddef.h>
+#include <stdint.h>
+#include <sys/param.h>
+#include <sys/shm.h>
+#include <sys/sysctl.h>
+#include <uvm/uvm_extern.h>
+
+#include "base/notreached.h"
+#include "base/posix/sysctl.h"
+#include "base/strings/string_util.h"
+
+namespace base {
+
+namespace {
+
+ByteCount AmountOfMemory(int pages_name) {
+  long pages = sysconf(pages_name);
+  long page_size = sysconf(_SC_PAGESIZE);
+  if (pages < 0 || page_size < 0) {
+    return ByteCount(0);
+  }
+  return ByteCount(page_size) * page_size;
+}
+
+}  // namespace
+
+// static
+int SysInfo::NumberOfProcessors() {
+  int mib[] = {CTL_HW, HW_NCPU};
+  int ncpu;
+  size_t size = sizeof(ncpu);
+  if (sysctl(mib, std::size(mib), &ncpu, &size, NULL, 0) < 0) {
+    NOTREACHED();
+  }
+  return ncpu;
+}
+
+// static
+std::string SysInfo::CPUModelName() {
+  int mib[] = { CTL_HW, HW_MODEL };
+  char name[256];
+  size_t size = std::size(name);
+
+  if (sysctl(mib, std::size(mib), &name, &size, NULL, 0) == 0) {
+    return name;
+  }
+
+  return std::string();
+}
+
+// static
+ByteCount SysInfo::AmountOfPhysicalMemoryImpl() {
+  return AmountOfMemory(_SC_PHYS_PAGES);
+}
+
+// static
+ByteCount SysInfo::AmountOfAvailablePhysicalMemoryImpl() {
+  // With NetBSD-11
+  //return AmountOfMemory(_SC_AVPHYS_PAGES);
+  struct uvmexp_sysctl uvmexp;
+  size_t len = sizeof(uvmexp);
+  int mib[] = { CTL_VM, VM_UVMEXP2 };
+  if (sysctl(mib, std::size(mib), &uvmexp, &len, NULL, 0) <0) {
+    NOTREACHED();
+    return ByteCount();
+  }
+  return ByteCount(uvmexp.free);
+}
+
+// static
+uint64_t SysInfo::MaxSharedMemorySize() {
+  int mib[] = {CTL_KERN, KERN_SYSVIPC, KERN_SYSVIPC_SHMMAX};
+  size_t limit;
+  size_t size = sizeof(limit);
+  if (sysctl(mib, std::size(mib), &limit, &size, NULL, 0) < 0) {
+    NOTREACHED();
+  }
+  return static_cast<uint64_t>(limit);
+}
+
+// static
+SysInfo::HardwareInfo SysInfo::GetHardwareInfoSync() {
+  HardwareInfo info;
+  // Set the manufacturer to "NetBSD" and the model to
+  // an empty string.
+  info.manufacturer = "NetBSD";
+  info.model = HardwareModelName();
+  DCHECK(IsStringUTF8(info.manufacturer));
+  DCHECK(IsStringUTF8(info.model));
+  return info;
+}
+
+}  // namespace base
