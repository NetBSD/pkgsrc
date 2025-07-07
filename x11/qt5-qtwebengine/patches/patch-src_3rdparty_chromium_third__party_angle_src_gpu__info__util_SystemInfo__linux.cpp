$NetBSD: patch-src_3rdparty_chromium_third__party_angle_src_gpu__info__util_SystemInfo__linux.cpp,v 1.2 2025/07/07 13:50:44 wiz Exp $

--- src/3rdparty/chromium/third_party/angle/src/gpu_info_util/SystemInfo_linux.cpp.orig	2020-07-15 19:01:32.000000000 +0000
+++ src/3rdparty/chromium/third_party/angle/src/gpu_info_util/SystemInfo_linux.cpp
@@ -71,10 +71,17 @@ bool GetPCIDevicesWithLibPCI(std::vector
 
 bool GetSystemInfo(SystemInfo *info)
 {
+#if defined(OS_OPENBSD) || defined(OS_FREEBSD) || defined(OS_NETBSD)
+    if (!CollectMesaCardInfo(&(info->gpus)))
+    {
+        return false;
+    }
+#else
     if (!GetPCIDevicesWithLibPCI(&(info->gpus)))
     {
         return false;
     }
+#endif
 
     if (info->gpus.size() == 0)
     {
