$NetBSD: patch-third__party_angle_src_gpu__info__util_SystemInfo__internal.h,v 1.1 2025/02/06 09:58:22 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/angle/src/gpu_info_util/SystemInfo_internal.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ third_party/angle/src/gpu_info_util/SystemInfo_internal.h
@@ -15,6 +15,13 @@
 namespace angle
 {
 
+#if defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__NetBSD__)
+bool CollectMesaCardInfo(std::vector<GPUDeviceInfo> *devices);                
+#if defined(__FreeBSD__)
+bool GetPCIDevicesFreeBSD(std::vector<GPUDeviceInfo> *devices);
+#endif
+#endif
+
 // Defined in SystemInfo_libpci when GPU_INFO_USE_LIBPCI is defined.
 bool GetPCIDevicesWithLibPCI(std::vector<GPUDeviceInfo> *devices);
 // Defined in SystemInfo_x11 when GPU_INFO_USE_X11 is defined.
