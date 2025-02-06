$NetBSD: patch-content_public_browser_zygote__host_zygote__host__linux.h,v 1.1 2025/02/06 09:58:07 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/public/browser/zygote_host/zygote_host_linux.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ content/public/browser/zygote_host/zygote_host_linux.h
@@ -35,11 +35,13 @@ class ZygoteHost {
   // after the first render has been forked.
   virtual int GetRendererSandboxStatus() = 0;
 
+#if !BUILDFLAG(IS_BSD)
   // Adjust the OOM score of the given renderer's PID.  The allowed
   // range for the score is [0, 1000], where higher values are more
   // likely to be killed by the OOM killer.
   virtual void AdjustRendererOOMScore(base::ProcessHandle process_handle,
                                       int score) = 0;
+#endif
 
 #if BUILDFLAG(IS_CHROMEOS)
   // Reinitialize logging for the Zygote processes. Needed on ChromeOS, which
