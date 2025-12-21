$NetBSD: patch-src_3rdparty_chromium_third__party_dawn_src_dawn_native_vulkan_BackendVk.cpp,v 1.1 2025/12/21 09:38:42 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/third_party/dawn/src/dawn/native/vulkan/BackendVk.cpp.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/third_party/dawn/src/dawn/native/vulkan/BackendVk.cpp
@@ -56,7 +56,7 @@ constexpr char kSwiftshaderLibName[] = "
 #endif
 
 #if DAWN_PLATFORM_IS(LINUX)
-#if DAWN_PLATFORM_IS(ANDROID)
+#if DAWN_PLATFORM_IS(ANDROID) || DAWN_PLATFORM_IS(BSD)
 constexpr char kVulkanLibName[] = "libvulkan.so";
 #else
 constexpr char kVulkanLibName[] = "libvulkan.so.1";
