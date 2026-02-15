$NetBSD: patch-services_shape__detection_shape__detection__sandbox__hook.h,v 1.11 2026/02/15 09:04:10 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- services/shape_detection/shape_detection_sandbox_hook.h.orig	2026-02-03 22:07:10.000000000 +0000
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
 
