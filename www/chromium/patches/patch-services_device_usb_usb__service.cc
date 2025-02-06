$NetBSD: patch-services_device_usb_usb__service.cc,v 1.1 2025/02/06 09:58:20 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- services/device/usb/usb_service.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ services/device/usb/usb_service.cc
@@ -21,12 +21,16 @@
 
 #if BUILDFLAG(IS_ANDROID)
 #include "services/device/usb/usb_service_android.h"
-#elif defined(USE_UDEV)
+#elif defined(USE_UDEV) && !BUILDFLAG(IS_BSD)
 #include "services/device/usb/usb_service_linux.h"
 #elif BUILDFLAG(IS_MAC)
 #include "services/device/usb/usb_service_impl.h"
 #elif BUILDFLAG(IS_WIN)
 #include "services/device/usb/usb_service_win.h"
+#elif BUILDFLAG(IS_OPENBSD)
+#include "services/device/usb/usb_service_impl.h"
+#elif BUILDFLAG(IS_FREEBSD) || BUILDFLAG(IS_NETBSD)
+#include "services/device/usb/usb_service_fake.h"
 #endif
 
 namespace device {
@@ -49,12 +53,14 @@ constexpr base::TaskTraits UsbService::k
 std::unique_ptr<UsbService> UsbService::Create() {
 #if BUILDFLAG(IS_ANDROID)
   return base::WrapUnique(new UsbServiceAndroid());
-#elif defined(USE_UDEV)
+#elif defined(USE_UDEV) && !BUILDFLAG(IS_BSD)
   return base::WrapUnique(new UsbServiceLinux());
 #elif BUILDFLAG(IS_WIN)
   return base::WrapUnique(new UsbServiceWin());
 #elif BUILDFLAG(IS_MAC)
   return base::WrapUnique(new UsbServiceImpl());
+#elif BUILDFLAG(IS_BSD)
+  return base::WrapUnique(new UsbServiceImpl());
 #else
   return nullptr;
 #endif
