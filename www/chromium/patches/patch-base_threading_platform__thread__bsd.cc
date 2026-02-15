$NetBSD: patch-base_threading_platform__thread__bsd.cc,v 1.15 2026/02/15 09:03:56 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/threading/platform_thread_bsd.cc.orig	2026-02-14 15:42:44.582489103 +0000
+++ base/threading/platform_thread_bsd.cc
@@ -0,0 +1,41 @@
+// Copyright 2023 The Chromium Authors
+// Use of this source code is governed by a BSD-style license that can be
+// found in the LICENSE file.
+// Description: These are stubs for *BSD.
+
+#include "base/notimplemented.h"
+#include "base/threading/platform_thread.h"
+
+namespace base {
+namespace internal {
+
+void SetCurrentThreadTypeImpl(ThreadType thread_type,
+                              MessagePumpType pump_type_hint,
+                              bool may_change_affinity) {
+  NOTIMPLEMENTED();
+  return;
+}
+
+bool CanSetThreadTypeToRealtimeAudio() {
+  return false;
+}
+
+PlatformPriorityOverride SetThreadTypeOverride(
+    PlatformThreadHandle thread_handle,
+    ThreadType thread_type) {
+  return false;
+}
+
+void RemoveThreadTypeOverride(
+    PlatformThreadHandle thread_handle,
+    const PlatformPriorityOverride& priority_override_handle,
+    ThreadType initial_thread_type) {}
+
+}  // namespace internal
+
+// static
+void PlatformThreadBase::SetName(const std::string& name) {
+  SetNameCommon(name);
+}
+
+}  // namespace base
