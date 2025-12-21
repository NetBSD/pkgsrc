$NetBSD: patch-src_3rdparty_chromium_services_device_public_cpp_generic__sensor_sensor__reading.h,v 1.1 2025/12/21 09:38:37 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/services/device/public/cpp/generic_sensor/sensor_reading.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/services/device/public/cpp/generic_sensor/sensor_reading.h
@@ -8,6 +8,8 @@
 #include <stddef.h>
 #include <stdint.h>
 
+#include <cstdint>
+
 #include <type_traits>
 
 namespace device {
