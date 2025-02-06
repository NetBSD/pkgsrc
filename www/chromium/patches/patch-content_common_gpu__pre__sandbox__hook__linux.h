$NetBSD: patch-content_common_gpu__pre__sandbox__hook__linux.h,v 1.1 2025/02/06 09:58:07 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/common/gpu_pre_sandbox_hook_linux.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ content/common/gpu_pre_sandbox_hook_linux.h
@@ -5,8 +5,13 @@
 #ifndef CONTENT_COMMON_GPU_PRE_SANDBOX_HOOK_LINUX_H_
 #define CONTENT_COMMON_GPU_PRE_SANDBOX_HOOK_LINUX_H_
 
+#include "build/build_config.h"
 #include "base/component_export.h"
+#if BUILDFLAG(IS_BSD)
+#include "sandbox/policy/sandbox.h"
+#else
 #include "sandbox/policy/linux/sandbox_linux.h"
+#endif
 
 namespace content {
 
