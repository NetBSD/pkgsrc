$NetBSD: patch-platform_media_libaom_config_linux_arm_config_aom__config.h,v 1.1 2024/07/29 18:13:48 nia Exp $

Runtime CPU detection on ARM is currently unimplemented for anything
except Linux.

--- platform/media/libaom/config/linux/arm/config/aom_config.h.orig	2024-07-29 11:09:32.665087168 +0000
+++ platform/media/libaom/config/linux/arm/config/aom_config.h
@@ -59,7 +59,11 @@
 #define CONFIG_RD_DEBUG 0
 #define CONFIG_REALTIME_ONLY 0
 #define CONFIG_RT_ML_PARTITIONING 0
+#ifdef __linux
 #define CONFIG_RUNTIME_CPU_DETECT 1
+#else
+#define CONFIG_RUNTIME_CPU_DETECT 0
+#endif
 #define CONFIG_SHARED 0
 #define CONFIG_SIZE_LIMIT 0
 #define CONFIG_SPATIAL_RESAMPLING 1
