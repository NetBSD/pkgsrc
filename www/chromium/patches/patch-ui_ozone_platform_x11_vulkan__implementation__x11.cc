$NetBSD: patch-ui_ozone_platform_x11_vulkan__implementation__x11.cc,v 1.8 2025/10/16 19:43:38 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/ozone/platform/x11/vulkan_implementation_x11.cc.orig	2025-10-13 21:41:26.000000000 +0000
+++ ui/ozone/platform/x11/vulkan_implementation_x11.cc
@@ -59,7 +59,11 @@ bool VulkanImplementationX11::Initialize
 
     path = path.Append("libvk_swiftshader.so");
   } else {
+#if BUILDFLAG(IS_BSD) 
+    path = base::FilePath("libvulkan.so");
+#else
     path = base::FilePath("libvulkan.so.1");
+#endif
   }
 
   return vulkan_instance_.Initialize(path, required_extensions, {});
