$NetBSD: patch-gpu_config_gpu__finch__features.h,v 1.1 2026/03/14 12:40:35 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- gpu/config/gpu_finch_features.h.orig	2026-03-11 22:12:25.000000000 +0000
+++ gpu/config/gpu_finch_features.h
@@ -102,7 +102,7 @@ GPU_CONFIG_EXPORT BASE_DECLARE_FEATURE(k
 
 GPU_CONFIG_EXPORT BASE_DECLARE_FEATURE(kRemoveGPULegacyIPC);
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 GPU_CONFIG_EXPORT BASE_DECLARE_FEATURE(kSharedImageStubHighPriority);
 #endif
 
