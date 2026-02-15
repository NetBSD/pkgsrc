$NetBSD: patch-services_device_public_cpp_generic__sensor_sensor__reading.h,v 1.15 2026/02/15 09:04:09 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- services/device/public/cpp/generic_sensor/sensor_reading.h.orig	2026-02-03 22:07:10.000000000 +0000
+++ services/device/public/cpp/generic_sensor/sensor_reading.h
@@ -8,6 +8,8 @@
 #include <stddef.h>
 #include <stdint.h>
 
+#include <cstdint>
+
 #include <type_traits>
 
 namespace device {
