$NetBSD: patch-base_threading_platform__thread__bsd.cc,v 1.14 2026/01/19 16:14:07 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/threading/platform_thread_bsd.cc.orig	2026-01-19 14:53:54.431821625 +0000
+++ base/threading/platform_thread_bsd.cc
@@ -0,0 +1,39 @@
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
+                              MessagePumpType pump_type_hint) {
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
+void RemoveThreadTypeOverrideImpl(
+    const PlatformPriorityOverride& priority_override_handle,
+    ThreadType thread_type) {}
+
+}  // namespace internal
+
+// static
+void PlatformThreadBase::SetName(const std::string& name) {
+  SetNameCommon(name);
+}
+
+}  // namespace base
