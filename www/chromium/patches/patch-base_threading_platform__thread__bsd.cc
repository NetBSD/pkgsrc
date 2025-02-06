$NetBSD: patch-base_threading_platform__thread__bsd.cc,v 1.1 2025/02/06 09:57:43 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/threading/platform_thread_bsd.cc.orig	2024-12-21 10:25:09.653322994 +0000
+++ base/threading/platform_thread_bsd.cc
@@ -0,0 +1,31 @@
+// Copyright 2023 The Chromium Authors
+// Use of this source code is governed by a BSD-style license that can be
+// found in the LICENSE file.
+// Description: These are stubs for *BSD.
+
+#include "base/threading/platform_thread.h"
+
+namespace base {
+namespace internal {
+
+bool CanSetThreadTypeToRealtimeAudio() {
+  return false;
+}
+
+bool SetCurrentThreadTypeForPlatform(ThreadType thread_type,
+                                MessagePumpType pump_type_hint) {
+  return false;
+}
+
+std::optional<ThreadPriorityForTest>
+GetCurrentThreadPriorityForPlatformForTest() {
+  return std::nullopt;
+}
+}  // namespace internal
+
+// static
+void PlatformThreadBase::SetName(const std::string& name) {
+  SetNameCommon(name);
+}
+
+}  // namespace base
