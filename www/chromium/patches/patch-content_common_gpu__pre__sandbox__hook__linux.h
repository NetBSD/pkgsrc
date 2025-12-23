$NetBSD: patch-content_common_gpu__pre__sandbox__hook__linux.h,v 1.13 2025/12/23 13:22:19 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/common/gpu_pre_sandbox_hook_linux.h.orig	2025-12-17 23:05:18.000000000 +0000
+++ content/common/gpu_pre_sandbox_hook_linux.h
@@ -7,7 +7,15 @@
 
 #include <vector>
 
+#include "build/build_config.h"
+
+#if BUILDFLAG(IS_BSD)
+#include "sandbox/policy/sandbox.h"
+#include "sandbox/linux/syscall_broker/broker_command.h"
+#include "sandbox/linux/syscall_broker/broker_file_permission.h"
+#else
 #include "sandbox/policy/linux/sandbox_linux.h"
+#endif
 
 namespace sandbox::syscall_broker {
 class BrokerFilePermission;
