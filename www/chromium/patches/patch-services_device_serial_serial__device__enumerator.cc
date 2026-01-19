$NetBSD: patch-services_device_serial_serial__device__enumerator.cc,v 1.14 2026/01/19 16:14:19 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- services/device/serial/serial_device_enumerator.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ services/device/serial/serial_device_enumerator.cc
@@ -12,7 +12,7 @@
 #include "build/build_config.h"
 #include "components/device_event_log/device_event_log.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "services/device/serial/serial_device_enumerator_linux.h"
 #elif BUILDFLAG(IS_MAC)
 #include "services/device/serial/serial_device_enumerator_mac.h"
@@ -27,7 +27,7 @@ namespace device {
 // static
 std::unique_ptr<SerialDeviceEnumerator> SerialDeviceEnumerator::Create(
     scoped_refptr<base::SingleThreadTaskRunner> ui_task_runner) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return SerialDeviceEnumeratorLinux::Create();
 #elif BUILDFLAG(IS_MAC)
   return std::make_unique<SerialDeviceEnumeratorMac>();
