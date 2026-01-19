$NetBSD: patch-services_shape__detection_shape__detection__sandbox__hook.h,v 1.10 2026/01/19 16:14:19 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- services/shape_detection/shape_detection_sandbox_hook.h.orig	2026-01-07 00:50:30.000000000 +0000
+++ services/shape_detection/shape_detection_sandbox_hook.h
@@ -5,7 +5,13 @@
 #ifndef SERVICES_SHAPE_DETECTION_SHAPE_DETECTION_SANDBOX_HOOK_H_
 #define SERVICES_SHAPE_DETECTION_SHAPE_DETECTION_SANDBOX_HOOK_H_
 
+#include "build/build_config.h"
+
+#if BUILDFLAG(IS_BSD)
+#include "sandbox/policy/sandbox.h"
+#else
 #include "sandbox/policy/linux/sandbox_linux.h"
+#endif
 
 namespace shape_detection {
 
