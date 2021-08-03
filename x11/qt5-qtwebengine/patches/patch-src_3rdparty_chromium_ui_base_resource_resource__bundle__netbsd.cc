$NetBSD: patch-src_3rdparty_chromium_ui_base_resource_resource__bundle__netbsd.cc,v 1.1 2021/08/03 21:04:36 markd Exp $

--- src/3rdparty/chromium/ui/base/resource/resource_bundle_netbsd.cc.orig	2020-07-18 12:14:11.789023668 +0000
+++ src/3rdparty/chromium/ui/base/resource/resource_bundle_netbsd.cc
@@ -0,0 +1,21 @@
+// Copyright 2017 The Chromium Authors. All rights reserved.
+// Use of this source code is governed by a BSD-style license that can be
+// found in the LICENSE file.
+
+#include "ui/base/resource/resource_bundle.h"
+
+#include "base/logging.h"
+#include "base/macros.h"
+#include "ui/gfx/image/image.h"
+
+namespace ui {
+
+void ResourceBundle::LoadCommonResources() {
+  LoadChromeResources();
+}
+
+gfx::Image& ResourceBundle::GetNativeImageNamed(int resource_id) {
+  return GetImageNamed(resource_id);
+}
+
+}  // namespace ui
