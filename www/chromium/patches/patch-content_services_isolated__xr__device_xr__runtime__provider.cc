$NetBSD: patch-content_services_isolated__xr__device_xr__runtime__provider.cc,v 1.1 2026/11/08 15:39:04 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/services/isolated_xr_device/xr_runtime_provider.cc.orig	2026-11-02 23:22:33.000000000 +0000
+++ content/services/isolated_xr_device/xr_runtime_provider.cc
@@ -21,7 +21,7 @@
 
 #if BUILDFLAG(IS_WIN)
 #include "device/vr/openxr/windows/openxr_platform_helper_windows.h"
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "device/vr/openxr/linux/openxr_platform_helper_linux.h"
 #endif
 #endif
@@ -133,7 +133,7 @@ void IsolatedXRRuntimeProvider::SetupPol
 #if BUILDFLAG(IS_WIN)
     openxr_platform_helper_ =
         std::make_unique<device::OpenXrPlatformHelperWindows>();
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     openxr_platform_helper_ =
         std::make_unique<device::OpenXrPlatformHelperLinux>();
 #endif
