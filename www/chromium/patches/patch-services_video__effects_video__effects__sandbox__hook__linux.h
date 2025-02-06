$NetBSD: patch-services_video__effects_video__effects__sandbox__hook__linux.h,v 1.1 2025/02/06 09:58:21 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- services/video_effects/video_effects_sandbox_hook_linux.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ services/video_effects/video_effects_sandbox_hook_linux.h
@@ -5,7 +5,13 @@
 #ifndef SERVICES_VIDEO_EFFECTS_VIDEO_EFFECTS_SANDBOX_HOOK_LINUX_H_
 #define SERVICES_VIDEO_EFFECTS_VIDEO_EFFECTS_SANDBOX_HOOK_LINUX_H_
 
+#include "build/build_config.h"
+
+#if BUILDFLAG(IS_BSD)
+#include "sandbox/policy/sandbox.h"
+#else
 #include "sandbox/policy/linux/sandbox_linux.h"
+#endif
 
 namespace video_effects {
 
