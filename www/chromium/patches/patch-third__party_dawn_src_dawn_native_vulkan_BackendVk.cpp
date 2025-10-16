$NetBSD: patch-third__party_dawn_src_dawn_native_vulkan_BackendVk.cpp,v 1.8 2025/10/16 19:43:34 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/dawn/src/dawn/native/vulkan/BackendVk.cpp.orig	2025-10-13 21:41:26.000000000 +0000
+++ third_party/dawn/src/dawn/native/vulkan/BackendVk.cpp
@@ -56,7 +56,7 @@ constexpr char kSwiftshaderLibName[] = "
 #endif
 
 #if DAWN_PLATFORM_IS(LINUX)
-#if DAWN_PLATFORM_IS(ANDROID)
+#if DAWN_PLATFORM_IS(ANDROID) || DAWN_PLATFORM_IS(BSD)
 constexpr char kVulkanLibName[] = "libvulkan.so";
 #else
 constexpr char kVulkanLibName[] = "libvulkan.so.1";
