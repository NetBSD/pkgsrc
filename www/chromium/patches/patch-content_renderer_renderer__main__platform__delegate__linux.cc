$NetBSD: patch-content_renderer_renderer__main__platform__delegate__linux.cc,v 1.32 2026/11/08 15:39:04 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/renderer/renderer_main_platform_delegate_linux.cc.orig	2026-11-02 23:22:33.000000000 +0000
+++ content/renderer/renderer_main_platform_delegate_linux.cc
@@ -51,6 +51,7 @@ bool RendererMainPlatformDelegate::Enabl
   // any renderer has been started.
   // Here, we test that the status of SeccompBpf in the renderer is consistent
   // with what SandboxLinux::GetStatus() said we would do.
+#if !BUILDFLAG(IS_BSD)
   auto* linux_sandbox = sandbox::policy::SandboxLinux::GetInstance();
   if (linux_sandbox->GetStatus() & sandbox::policy::SandboxLinux::kSeccompBPF) {
     CHECK(linux_sandbox->seccomp_bpf_started());
@@ -72,6 +73,7 @@ bool RendererMainPlatformDelegate::Enabl
     CHECK_EQ(errno, EPERM);
   }
 #endif  // __x86_64__
+#endif
 
   return true;
 }
