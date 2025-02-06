$NetBSD: patch-services_video__effects_video__effects__sandbox__hook__linux.cc,v 1.1 2025/02/06 09:58:21 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- services/video_effects/video_effects_sandbox_hook_linux.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ services/video_effects/video_effects_sandbox_hook_linux.cc
@@ -6,7 +6,13 @@
 
 #include <dlfcn.h>
 
+#include "build/build_config.h"
+
+#if BUILDFLAG(IS_BSD)
+#include "sandbox/policy/sandbox.h"
+#else
 #include "sandbox/policy/linux/sandbox_linux.h"
+#endif
 #include "services/on_device_model/ml/chrome_ml.h"
 
 namespace video_effects {
@@ -29,8 +35,10 @@ bool VideoEffectsPreSandboxHook(
     DVLOG(1) << "Successfully opened Chrome ML shared library.";
   }
 
+#if !BUILDFLAG(IS_BSD)
   auto* instance = sandbox::policy::SandboxLinux::GetInstance();
   instance->EngageNamespaceSandboxIfPossible();
+#endif
   return true;
 }
 
