$NetBSD: patch-gpu_vulkan_vulkan__util.cc,v 1.25 2026/09/02 13:13:32 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- gpu/vulkan/vulkan_util.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ gpu/vulkan/vulkan_util.cc
@@ -278,7 +278,7 @@ bool CheckVulkanCompatibilities(
     }
   }
 
-#if BUILDFLAG(IS_LINUX) && !defined(OZONE_PLATFORM_IS_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && !defined(OZONE_PLATFORM_IS_X11)
   // Vulkan is only supported with X11 on Linux for now.
   return false;
 #else
