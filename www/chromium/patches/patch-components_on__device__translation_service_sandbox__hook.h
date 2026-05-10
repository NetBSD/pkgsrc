$NetBSD: patch-components_on__device__translation_service_sandbox__hook.h,v 1.5 2026/05/10 15:29:55 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/on_device_translation/service/sandbox_hook.h.orig	2026-04-28 23:05:57.000000000 +0200
+++ components/on_device_translation/service/sandbox_hook.h
@@ -5,7 +5,13 @@
 #ifndef COMPONENTS_ON_DEVICE_TRANSLATION_SERVICE_SANDBOX_HOOK_H_
 #define COMPONENTS_ON_DEVICE_TRANSLATION_SERVICE_SANDBOX_HOOK_H_
 
+#include "build/build_config.h"
+
+#if BUILDFLAG(IS_BSD)
+#include "sandbox/policy/sandbox.h"
+#else
 #include "sandbox/policy/linux/sandbox_linux.h"
+#endif
 
 namespace on_device_translation {
 
