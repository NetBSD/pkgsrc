$NetBSD: patch-content_utility_speech_speech__recognition__sandbox__hook__linux.h,v 1.14 2026/01/19 16:14:15 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/utility/speech/speech_recognition_sandbox_hook_linux.h.orig	2026-01-07 00:50:30.000000000 +0000
+++ content/utility/speech/speech_recognition_sandbox_hook_linux.h
@@ -5,7 +5,13 @@
 #ifndef CONTENT_UTILITY_SPEECH_SPEECH_RECOGNITION_SANDBOX_HOOK_LINUX_H_
 #define CONTENT_UTILITY_SPEECH_SPEECH_RECOGNITION_SANDBOX_HOOK_LINUX_H_
 
+#include "build/build_config.h"
+
+#if BUILDFLAG(IS_BSD)
+#include "sandbox/policy/sandbox.h"
+#else
 #include "sandbox/policy/linux/sandbox_linux.h"
+#endif
 
 namespace speech {
 
