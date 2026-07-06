$NetBSD: patch-ui_gl_gl__switches.cc,v 1.22 2026/07/06 13:07:01 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/gl/gl_switches.cc.orig	2026-06-23 23:37:18.000000000 +0000
+++ ui/gl/gl_switches.cc
@@ -16,7 +16,7 @@
 #endif
 
 #if BUILDFLAG(ENABLE_VULKAN) && \
-    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID))
+    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD))
 #include <vulkan/vulkan_core.h>
 #include "third_party/angle/src/gpu_info_util/SystemInfo.h"  // nogncheck
 #endif  // BUILDFLAG(ENABLE_VULKAN) && (BUILDFLAG(IS_LINUX) ||
@@ -316,7 +316,7 @@ bool IsDefaultANGLEVulkan() {
   }
 #endif  // BUILDFLAG(IS_ANDROID)
 #if BUILDFLAG(ENABLE_VULKAN) && \
-    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID))
+    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD))
   angle::SystemInfo system_info;
   {
     TRACE_EVENT("gpu,startup", "angle::GetSystemInfoVulkan");
@@ -398,7 +398,7 @@ bool IsDefaultANGLEVulkan() {
   }
 #endif  // BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // AMDVLK driver is buggy, so disable Vulkan with AMDVLK for now.
   // crbug.com/1340081
   if (active_gpu.driverId == VK_DRIVER_ID_AMD_OPEN_SOURCE)
