$NetBSD: patch-ui_ozone_platform_wayland_gpu_vulkan__implementation__wayland.cc,v 1.5 2025/08/13 07:44:34 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/ozone/platform/wayland/gpu/vulkan_implementation_wayland.cc.orig	2025-07-29 22:51:44.000000000 +0000
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
