$NetBSD: patch-services_device_public_cpp_generic__sensor_sensor__reading.h,v 1.7 2025/09/12 16:02:33 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- services/device/public/cpp/generic_sensor/sensor_reading.h.orig	2025-09-08 23:21:33.000000000 +0000
+++ services/device/public/cpp/generic_sensor/sensor_reading.h
@@ -8,6 +8,8 @@
 #include <stddef.h>
 #include <stdint.h>
 
+#include <cstdint>
+
 #include <type_traits>
 
 namespace device {
