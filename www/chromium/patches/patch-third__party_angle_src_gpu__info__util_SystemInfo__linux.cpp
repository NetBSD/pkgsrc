$NetBSD: patch-third__party_angle_src_gpu__info__util_SystemInfo__linux.cpp,v 1.6 2025/09/08 13:24:31 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/angle/src/gpu_info_util/SystemInfo_linux.cpp.orig	2025-08-29 18:50:09.000000000 +0000
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
     if (!GetPCIDevicesWithLibPCI(&(info->gpus)))
     {
 #if defined(ANGLE_USE_VULKAN_SYSTEM_INFO)
@@ -85,6 +103,7 @@ bool GetSystemInfo(SystemInfo *info)
     {
         return false;
     }
+#endif
 
     GetDualGPUInfo(info);
 
