$NetBSD: patch-content_services_isolated__xr__device_xr__sandbox__hook__linux.h,v 1.2 2026/11/08 15:39:04 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/services/isolated_xr_device/xr_sandbox_hook_linux.h.orig	2026-11-02 23:22:33.000000000 +0000
+++ content/services/isolated_xr_device/xr_sandbox_hook_linux.h
@@ -9,7 +9,11 @@
 #include <string>
 #include <string_view>
 
+#if defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__NetBSD__)
+#include "sandbox/policy/sandbox.h"
+#else
 #include "sandbox/policy/linux/sandbox_linux.h"
+#endif
 
 namespace vr {
 
