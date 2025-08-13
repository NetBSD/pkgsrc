$NetBSD: patch-components_services_on__device__translation_sandbox__hook.h,v 1.5 2025/08/13 07:44:24 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/services/on_device_translation/sandbox_hook.h.orig	2025-07-29 22:51:44.000000000 +0000
+++ components/services/on_device_translation/sandbox_hook.h
@@ -5,7 +5,13 @@
 #ifndef COMPONENTS_SERVICES_ON_DEVICE_TRANSLATION_SANDBOX_HOOK_H_
 #define COMPONENTS_SERVICES_ON_DEVICE_TRANSLATION_SANDBOX_HOOK_H_
 
+#include "build/build_config.h"
+
+#if BUILDFLAG(IS_BSD)
+#include "sandbox/policy/sandbox.h"
+#else
 #include "sandbox/policy/linux/sandbox_linux.h"
+#endif
 
 namespace on_device_translation {
 
