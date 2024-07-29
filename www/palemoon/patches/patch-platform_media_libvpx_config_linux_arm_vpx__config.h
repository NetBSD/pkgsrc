$NetBSD: patch-platform_media_libvpx_config_linux_arm_vpx__config.h,v 1.1 2024/07/29 18:13:48 nia Exp $

Runtime CPU detection on ARM is currently unimplemented for anything
except Linux.

--- platform/media/libvpx/config/linux/arm/vpx_config.h.orig	2024-07-29 10:28:36.006671626 +0000
+++ platform/media/libvpx/config/linux/arm/vpx_config.h
@@ -48,7 +48,11 @@
 #define CONFIG_DEBUG_LIBS 0
 #define CONFIG_DEQUANT_TOKENS 0
 #define CONFIG_DC_RECON 0
+#ifdef __linux
 #define CONFIG_RUNTIME_CPU_DETECT 1
+#else
+#define CONFIG_RUNTIME_CPU_DETECT 0
+#endif
 #define CONFIG_POSTPROC 0
 #define CONFIG_VP9_POSTPROC 0
 #define CONFIG_MULTITHREAD 1
