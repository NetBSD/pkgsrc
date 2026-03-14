$NetBSD: patch-services_device_hid_hid__service.cc,v 1.16 2026/03/14 12:40:39 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- services/device/hid/hid_service.cc.orig	2026-03-11 22:12:25.000000000 +0000
+++ services/device/hid/hid_service.cc
@@ -19,12 +19,18 @@
 
 #if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && defined(USE_UDEV)
 #include "services/device/hid/hid_service_linux.h"
+#elif BUILDFLAG(IS_OPENBSD)
+#include "services/device/hid/hid_service_fido.h"
+#elif BUILDFLAG(IS_FREEBSD)
+#include "services/device/hid/hid_service_freebsd.h"
 #elif BUILDFLAG(IS_MAC)
 #include "services/device/hid/hid_service_mac.h"
 #elif BUILDFLAG(IS_WIN)
 #include "services/device/hid/hid_service_win.h"
 #elif BUILDFLAG(IS_FUCHSIA)
 #include "services/device/hid/hid_service_fuchsia.h"
+#elif BUILDFLAG(IS_NETBSD)
+#include "services/device/hid/hid_service_netbsd.h"
 #endif
 
 namespace device {
@@ -67,12 +73,18 @@ constexpr base::TaskTraits HidService::k
 std::unique_ptr<HidService> HidService::Create() {
 #if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && defined(USE_UDEV)
   return std::make_unique<HidServiceLinux>();
+#elif BUILDFLAG(IS_OPENBSD)
+  return std::make_unique<HidServiceFido>();
+#elif BUILDFLAG(IS_FREEBSD)
+  return std::make_unique<HidServiceFreeBSD>();
 #elif BUILDFLAG(IS_MAC)
   return std::make_unique<HidServiceMac>();
 #elif BUILDFLAG(IS_WIN)
   return std::make_unique<HidServiceWin>();
 #elif BUILDFLAG(IS_FUCHSIA)
   return std::make_unique<HidServiceFuchsia>();
+#elif BUILDFLAG(IS_NETBSD)
+  return std::make_unique<HidServiceNetBSD>();
 #else
   return nullptr;
 #endif
