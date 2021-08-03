$NetBSD: patch-src_3rdparty_chromium_third__party_angle_src_gpu__info__util_SystemInfo__internal.h,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/third_party/angle/src/gpu_info_util/SystemInfo_internal.h.orig	2020-07-15 19:01:32.000000000 +0000
+++ src/3rdparty/chromium/third_party/angle/src/gpu_info_util/SystemInfo_internal.h
@@ -16,6 +18,9 @@ namespace angle
 
 // Defined in SystemInfo_libpci when GPU_INFO_USE_LIBPCI is defined.
 bool GetPCIDevicesWithLibPCI(std::vector<GPUDeviceInfo> *devices);
+#if defined(OS_FREEBSD)
+bool GetPCIDevicesFreeBSD(std::vector<GPUDeviceInfo> *devices);
+#endif
 // Defined in SystemInfo_x11 when GPU_INFO_USE_X11 is defined.
 bool GetNvidiaDriverVersionWithXNVCtrl(std::string *version);
 
