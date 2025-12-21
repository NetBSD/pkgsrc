$NetBSD: patch-src_3rdparty_chromium_components_services_on__device__translation_sandbox__hook.h,v 1.1 2025/12/21 09:38:24 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/components/services/on_device_translation/sandbox_hook.h.orig	2025-11-14 07:55:10.000000000 +0000
+++ src/3rdparty/chromium/components/services/on_device_translation/sandbox_hook.h
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
 
