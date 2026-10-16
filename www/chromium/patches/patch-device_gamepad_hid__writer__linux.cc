$NetBSD: patch-device_gamepad_hid__writer__linux.cc,v 1.30 2026/10/16 15:30:54 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- device/gamepad/hid_writer_linux.cc.orig	2026-10-14 21:09:54.000000000 +0000
+++ device/gamepad/hid_writer_linux.cc
@@ -2,6 +2,8 @@
 // Use of this source code is governed by a BSD-style license that can be
 // found in the LICENSE file.
 
+#include <unistd.h>
+
 #include "device/gamepad/hid_writer_linux.h"
 
 #include <unistd.h>
