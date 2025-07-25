$NetBSD: patch-ui_ozone_platform_wayland_gpu_vulkan__implementation__wayland.cc,v 1.4 2025/07/25 16:17:24 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/ozone/platform/wayland/gpu/vulkan_implementation_wayland.cc.orig	2025-07-21 19:32:31.000000000 +0000
+++ ui/ozone/platform/wayland/gpu/vulkan_implementation_wayland.cc
@@ -38,7 +38,11 @@ bool VulkanImplementationWayland::Initia
 
     path = path.Append("libvk_swiftshader.so");
   } else {
+#if BUILDFLAG(IS_BSD)
+    path = base::FilePath("libvulkan.so");
+#else
     path = base::FilePath("libvulkan.so.1");
+#endif
   }
 
   return vulkan_instance_.Initialize(path, required_extensions, {});
