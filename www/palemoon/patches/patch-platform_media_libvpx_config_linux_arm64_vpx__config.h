$NetBSD: patch-platform_media_libvpx_config_linux_arm64_vpx__config.h,v 1.3 2026/05/19 07:31:59 nia Exp $

Fix build on NetBSD/aarch64.

https://repo.palemoon.org/MoonchildProductions/UXP/pulls/3094

--- platform/media/libvpx/config/linux/arm64/vpx_config.h.orig	2026-05-16 08:20:54.290983878 +0000
+++ platform/media/libvpx/config/linux/arm64/vpx_config.h
@@ -60,7 +60,11 @@
 #define CONFIG_DEBUG_LIBS 0
 #define CONFIG_DEQUANT_TOKENS 0
 #define CONFIG_DC_RECON 0
+#ifdef __linux__
 #define CONFIG_RUNTIME_CPU_DETECT 1
+#else
+#define CONFIG_RUNTIME_CPU_DETECT 0
+#endif
 #define CONFIG_POSTPROC 0
 #define CONFIG_VP9_POSTPROC 0
 #define CONFIG_MULTITHREAD 1
