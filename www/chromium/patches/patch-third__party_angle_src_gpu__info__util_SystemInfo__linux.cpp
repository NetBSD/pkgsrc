$NetBSD: patch-third__party_angle_src_gpu__info__util_SystemInfo__linux.cpp,v 1.17 2026/04/10 17:31:59 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/angle/src/gpu_info_util/SystemInfo_linux.cpp.orig	2026-04-06 16:25:54.000000000 +0000
+++ third_party/angle/src/gpu_info_util/SystemInfo_linux.cpp
@@ -71,6 +71,24 @@ bool GetPCIDevicesWithLibPCI(std::vector
 
 bool GetSystemInfo(SystemInfo *info)
 {
+#if defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__NetBSD__)
+    if (!CollectMesaCardInfo(&(info->gpus)))
+    {
+#if defined(__FreeBSD__)
+        if (!GetPCIDevicesFreeBSD(&(info->gpus)))
+        {
+#endif
+#if defined(ANGLE_USE_VULKAN_SYSTEM_INFO)
+            // Try vulkan backend to get GPU info
+            return GetSystemInfoVulkan(info);
+#else
+            return false;
+#endif
+#if defined(__FreeBSD__)
+        }
+#endif
+    }
+#else
     if (!GetPCIDevicesWithLibPCI(&(info->gpus)) || info->gpus.size() == 0)
     {
 #if defined(ANGLE_USE_VULKAN_SYSTEM_INFO)
@@ -80,6 +98,7 @@ bool GetSystemInfo(SystemInfo *info)
         return false;
 #endif  // defined(ANGLE_HAS_VULKAN_SYSTEM_INFO)
     }
+#endif
 
     GetDualGPUInfo(info);
 
