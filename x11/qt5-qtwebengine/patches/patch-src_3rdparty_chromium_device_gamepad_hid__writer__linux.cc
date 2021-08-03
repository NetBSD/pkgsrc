$NetBSD: patch-src_3rdparty_chromium_device_gamepad_hid__writer__linux.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/device/gamepad/hid_writer_linux.cc.orig	2020-07-08 21:40:43.000000000 +0000
+++ src/3rdparty/chromium/device/gamepad/hid_writer_linux.cc
@@ -4,6 +4,8 @@
 
 #include "device/gamepad/hid_writer_linux.h"
 
+#include <unistd.h>
+
 #include "base/posix/eintr_wrapper.h"
 
 namespace device {
