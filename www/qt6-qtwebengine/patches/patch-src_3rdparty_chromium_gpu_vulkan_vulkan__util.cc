$NetBSD: patch-src_3rdparty_chromium_gpu_vulkan_vulkan__util.cc,v 1.1 2025/12/21 09:38:30 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/gpu/vulkan/vulkan_util.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/gpu/vulkan/vulkan_util.cc
@@ -473,7 +473,7 @@ bool CheckVulkanCompatibilities(
     }
   }
 
-#if BUILDFLAG(IS_LINUX) && !defined(OZONE_PLATFORM_IS_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && !defined(OZONE_PLATFORM_IS_X11)
   // Vulkan is only supported with X11 on Linux for now.
   return false;
 #else
