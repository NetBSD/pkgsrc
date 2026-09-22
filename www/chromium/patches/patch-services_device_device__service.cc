$NetBSD: patch-services_device_device__service.cc,v 1.3 2026/09/22 13:41:29 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- services/device/device_service.cc.orig	2026-09-14 22:17:16.000000000 +0000
+++ services/device/device_service.cc
@@ -6,6 +6,8 @@
 
 #include <utility>
 
+#include "base/notimplemented.h"
+
 #include "base/functional/bind.h"
 #include "base/memory/weak_ptr.h"
 #include "base/task/single_thread_task_runner.h"
@@ -308,7 +310,7 @@ void DeviceService::BindSerialPortManage
   serial_port_manager_.AsyncCall(&SerialPortManagerImpl::Bind, FROM_HERE)
       .WithArgs(std::move(receiver));
 #else   // defined(IS_SERIAL_ENABLED_PLATFORM)
-  NOTREACHED() << "Serial devices not supported on this platform.";
+  NOTIMPLEMENTED() << "Serial devices not supported on this platform.";
 #endif  // defined(IS_SERIAL_ENABLED_PLATFORM)
 }
 
