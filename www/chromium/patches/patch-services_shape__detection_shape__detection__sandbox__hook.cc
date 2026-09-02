$NetBSD: patch-services_shape__detection_shape__detection__sandbox__hook.cc,v 1.21 2026/09/02 13:13:35 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- services/shape_detection/shape_detection_sandbox_hook.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ services/shape_detection/shape_detection_sandbox_hook.cc
@@ -32,8 +32,10 @@ bool ShapeDetectionPreSandboxHook(
     DVLOG(1) << "Successfully opened Chrome Shape Detection shared library.";
   }
 #endif  // BUILDFLAG(GOOGLE_CHROME_BRANDING)
+#if !BUILDFLAG(IS_BSD)
   auto* instance = sandbox::policy::SandboxLinux::GetInstance();
   instance->EngageNamespaceSandboxIfPossible();
+#endif
   return true;
 }
 
