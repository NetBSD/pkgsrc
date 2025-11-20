$NetBSD: patch-ui_ozone_platform_wayland_gpu_vulkan__implementation__wayland.cc,v 1.10 2025/11/20 08:36:25 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/ozone/platform/wayland/gpu/vulkan_implementation_wayland.cc.orig	2025-11-14 20:31:45.000000000 +0000
+++ ui/ozone/platform/wayland/gpu/vulkan_implementation_wayland.cc
@@ -39,7 +39,11 @@ bool VulkanImplementationWayland::Initia
 
     path = path.Append("libvk_swiftshader.so");
   } else {
+#if BUILDFLAG(IS_BSD)
+    path = base::FilePath("libvulkan.so");
+#else
     path = base::FilePath("libvulkan.so.1");
+#endif
   }
 
   return vulkan_instance_.Initialize(path, required_extensions, {});
