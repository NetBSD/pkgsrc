$NetBSD: patch-services_screen__ai_sandbox_screen__ai__sandbox__hook__linux.h,v 1.32 2026/11/08 15:39:08 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- services/screen_ai/sandbox/screen_ai_sandbox_hook_linux.h.orig	2026-11-02 23:22:33.000000000 +0000
+++ services/screen_ai/sandbox/screen_ai_sandbox_hook_linux.h
@@ -6,7 +6,13 @@
 #define SERVICES_SCREEN_AI_SANDBOX_SCREEN_AI_SANDBOX_HOOK_LINUX_H_
 
 #include "base/files/file_path.h"
+#include "build/build_config.h"
+
+#if BUILDFLAG(IS_BSD)
+#include "sandbox/policy/sandbox.h"
+#else
 #include "sandbox/policy/linux/sandbox_linux.h"
+#endif
 
 namespace screen_ai {
 
