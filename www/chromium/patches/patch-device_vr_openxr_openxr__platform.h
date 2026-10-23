$NetBSD: patch-device_vr_openxr_openxr__platform.h,v 1.5 2026/10/23 15:05:28 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- device/vr/openxr/openxr_platform.h.orig	2026-10-19 20:07:21.000000000 +0000
+++ device/vr/openxr/openxr_platform.h
@@ -21,7 +21,7 @@
 #elif BUILDFLAG(IS_ANDROID)
 #include <EGL/egl.h>
 #include <jni.h>
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include <vulkan/vulkan_core.h>
 #endif
 
