$NetBSD: patch-gpu_config_gpu__finch__features.h,v 1.16 2026/10/23 15:05:28 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- gpu/config/gpu_finch_features.h.orig	2026-10-19 20:07:21.000000000 +0000
+++ gpu/config/gpu_finch_features.h
@@ -204,7 +204,7 @@ GPU_CONFIG_EXPORT BASE_DECLARE_FEATURE(k
 
 GPU_CONFIG_EXPORT BASE_DECLARE_FEATURE(kRemoveGPULegacyIPC);
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 GPU_CONFIG_EXPORT BASE_DECLARE_FEATURE(kSharedImageStubHighPriority);
 #endif
 
