$NetBSD: patch-src_3rdparty_chromium_content_public_browser_zygote__host_zygote__host__linux.h,v 1.1 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/content/public/browser/zygote_host/zygote_host_linux.h.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/content/public/browser/zygote_host/zygote_host_linux.h
@@ -30,11 +30,13 @@ class ZygoteHost {
   // after the first render has been forked.
   virtual int GetRendererSandboxStatus() = 0;
 
+#if !defined(OS_BSD)
   // Adjust the OOM score of the given renderer's PID.  The allowed
   // range for the score is [0, 1000], where higher values are more
   // likely to be killed by the OOM killer.
   virtual void AdjustRendererOOMScore(base::ProcessHandle process_handle,
                                       int score) = 0;
+#endif
 };
 
 }  // namespace content
