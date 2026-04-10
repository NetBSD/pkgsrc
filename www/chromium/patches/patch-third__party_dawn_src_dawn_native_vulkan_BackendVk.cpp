$NetBSD: patch-third__party_dawn_src_dawn_native_vulkan_BackendVk.cpp,v 1.17 2026/04/10 17:32:00 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/dawn/src/dawn/native/vulkan/BackendVk.cpp.orig	2026-04-06 16:25:54.000000000 +0000
+++ third_party/dawn/src/dawn/native/vulkan/BackendVk.cpp
@@ -57,7 +57,7 @@ constexpr char kSwiftshaderLibName[] = "
 #endif
 
 #if DAWN_PLATFORM_IS(LINUX)
-#if DAWN_PLATFORM_IS(ANDROID)
+#if DAWN_PLATFORM_IS(ANDROID) || DAWN_PLATFORM_IS(BSD)
 constexpr char kVulkanLibName[] = "libvulkan.so";
 #else
 constexpr char kVulkanLibName[] = "libvulkan.so.1";
