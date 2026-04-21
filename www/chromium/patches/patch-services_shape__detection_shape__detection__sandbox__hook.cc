$NetBSD: patch-services_shape__detection_shape__detection__sandbox__hook.cc,v 1.14 2026/04/21 15:21:20 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- services/shape_detection/shape_detection_sandbox_hook.cc.orig	2026-04-14 23:31:37.000000000 +0200
+++ services/shape_detection/shape_detection_sandbox_hook.cc
@@ -31,8 +31,10 @@ bool ShapeDetectionPreSandboxHook(
     DVLOG(1) << "Successfully opened Chrome Shape Detection shared library.";
   }
 #endif  // BUILDFLAG(GOOGLE_CHROME_BRANDING)
+#if !BUILDFLAG(IS_BSD)
   auto* instance = sandbox::policy::SandboxLinux::GetInstance();
   instance->EngageNamespaceSandboxIfPossible();
+#endif
   return true;
 }
 
