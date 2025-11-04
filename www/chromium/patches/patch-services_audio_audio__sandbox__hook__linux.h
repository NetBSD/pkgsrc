$NetBSD: patch-services_audio_audio__sandbox__hook__linux.h,v 1.9 2025/11/04 14:55:45 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- services/audio/audio_sandbox_hook_linux.h.orig	2025-10-24 16:42:30.000000000 +0000
+++ services/audio/audio_sandbox_hook_linux.h
@@ -5,7 +5,13 @@
 #ifndef SERVICES_AUDIO_AUDIO_SANDBOX_HOOK_LINUX_H_
 #define SERVICES_AUDIO_AUDIO_SANDBOX_HOOK_LINUX_H_
 
+#include "build/build_config.h"
+
+#if BUILDFLAG(IS_BSD)
+#include "sandbox/policy/sandbox.h"
+#else
 #include "sandbox/policy/linux/sandbox_linux.h"
+#endif
 
 namespace audio {
 
