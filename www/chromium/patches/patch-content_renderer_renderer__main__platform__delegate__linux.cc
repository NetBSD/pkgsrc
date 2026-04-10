$NetBSD: patch-content_renderer_renderer__main__platform__delegate__linux.cc,v 1.17 2026/04/10 17:31:55 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/renderer/renderer_main_platform_delegate_linux.cc.orig	2026-04-06 16:25:54.000000000 +0000
+++ content/renderer/renderer_main_platform_delegate_linux.cc
@@ -44,6 +44,7 @@ bool RendererMainPlatformDelegate::Enabl
   // any renderer has been started.
   // Here, we test that the status of SeccompBpf in the renderer is consistent
   // with what SandboxLinux::GetStatus() said we would do.
+#if !BUILDFLAG(IS_BSD)
   auto* linux_sandbox = sandbox::policy::SandboxLinux::GetInstance();
   if (linux_sandbox->GetStatus() & sandbox::policy::SandboxLinux::kSeccompBPF) {
     CHECK(linux_sandbox->seccomp_bpf_started());
@@ -65,6 +66,7 @@ bool RendererMainPlatformDelegate::Enabl
     CHECK_EQ(errno, EPERM);
   }
 #endif  // __x86_64__
+#endif
 
   return true;
 }
