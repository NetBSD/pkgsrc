$NetBSD: patch-ui_ozone_platform_x11_vulkan__implementation__x11.cc,v 1.6 2025/09/08 13:24:35 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/ozone/platform/x11/vulkan_implementation_x11.cc.orig	2025-08-29 18:50:09.000000000 +0000
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
