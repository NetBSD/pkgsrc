$NetBSD: patch-src_3rdparty_chromium_services_shape__detection_shape__detection__sandbox__hook.cc,v 1.1 2026/04/30 06:39:42 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/services/shape_detection/shape_detection_sandbox_hook.cc.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/services/shape_detection/shape_detection_sandbox_hook.cc
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
 
