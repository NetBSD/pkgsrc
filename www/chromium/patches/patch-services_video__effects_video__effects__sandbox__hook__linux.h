$NetBSD: patch-services_video__effects_video__effects__sandbox__hook__linux.h,v 1.9 2025/11/04 14:55:45 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- services/video_effects/video_effects_sandbox_hook_linux.h.orig	2025-10-24 16:42:30.000000000 +0000
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
 
