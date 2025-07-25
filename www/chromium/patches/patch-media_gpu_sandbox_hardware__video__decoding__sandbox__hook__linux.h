$NetBSD: patch-media_gpu_sandbox_hardware__video__decoding__sandbox__hook__linux.h,v 1.4 2025/07/25 16:17:18 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/gpu/sandbox/hardware_video_decoding_sandbox_hook_linux.h.orig	2025-07-21 19:32:31.000000000 +0000
+++ media/gpu/sandbox/hardware_video_decoding_sandbox_hook_linux.h
@@ -5,7 +5,13 @@
 #ifndef MEDIA_GPU_SANDBOX_HARDWARE_VIDEO_DECODING_SANDBOX_HOOK_LINUX_H_
 #define MEDIA_GPU_SANDBOX_HARDWARE_VIDEO_DECODING_SANDBOX_HOOK_LINUX_H_
 
+#include "build/build_config.h"
+
+#if BUILDFLAG(IS_BSD)
+#include "sandbox/policy/sandbox.h"
+#else
 #include "sandbox/policy/linux/sandbox_linux.h"
+#endif
 
 namespace media {
 
