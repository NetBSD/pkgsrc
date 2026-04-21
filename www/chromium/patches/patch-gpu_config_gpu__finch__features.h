$NetBSD: patch-gpu_config_gpu__finch__features.h,v 1.3 2026/04/21 15:21:16 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- gpu/config/gpu_finch_features.h.orig	2026-04-14 23:31:37.000000000 +0200
+++ gpu/config/gpu_finch_features.h
@@ -107,7 +107,7 @@ GPU_CONFIG_EXPORT BASE_DECLARE_FEATURE(k
 
 GPU_CONFIG_EXPORT BASE_DECLARE_FEATURE(kRemoveGPULegacyIPC);
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 GPU_CONFIG_EXPORT BASE_DECLARE_FEATURE(kSharedImageStubHighPriority);
 #endif
 
