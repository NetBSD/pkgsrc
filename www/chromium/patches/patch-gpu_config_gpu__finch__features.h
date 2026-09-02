$NetBSD: patch-gpu_config_gpu__finch__features.h,v 1.10 2026/09/02 13:13:32 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- gpu/config/gpu_finch_features.h.orig	2026-08-31 22:47:51.000000000 +0000
+++ gpu/config/gpu_finch_features.h
@@ -187,7 +187,7 @@ GPU_CONFIG_EXPORT BASE_DECLARE_FEATURE(k
 
 GPU_CONFIG_EXPORT BASE_DECLARE_FEATURE(kRemoveGPULegacyIPC);
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 GPU_CONFIG_EXPORT BASE_DECLARE_FEATURE(kSharedImageStubHighPriority);
 #endif
 
