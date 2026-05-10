$NetBSD: patch-content_utility_on__device__model_on__device__model__sandbox__init.h,v 1.15 2026/05/10 15:29:58 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/utility/on_device_model/on_device_model_sandbox_init.h.orig	2026-04-28 23:05:57.000000000 +0200
+++ content/utility/on_device_model/on_device_model_sandbox_init.h
@@ -11,6 +11,10 @@
 #include "sandbox/policy/linux/sandbox_linux.h"
 #endif
 
+#if BUILDFLAG(IS_BSD)
+#include "sandbox/policy/sandbox.h"
+#endif
+
 namespace on_device_model {
 
 // Must be called in the service's process before sandbox initialization.
@@ -21,7 +25,7 @@ namespace on_device_model {
 // Must be called in the service's process after the run loop finished.
 [[nodiscard]] bool Shutdown();
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 void AddSandboxLinuxOptions(sandbox::policy::SandboxLinux::Options& options);
 
 [[nodiscard]] bool PreSandboxHook(
