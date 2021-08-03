$NetBSD: patch-src_3rdparty_chromium_services_service__manager_zygote_zygote__host__linux.h,v 1.1 2021/08/03 21:04:35 markd Exp $

Index: src/3rdparty/chromium/services/service_manager/zygote/zygote_host_linux.h
--- src/3rdparty/chromium/services/service_manager/zygote/zygote_host_linux.h.orig
+++ src/3rdparty/chromium/services/service_manager/zygote/zygote_host_linux.h
@@ -30,11 +30,13 @@ class ZygoteHost {
   // after the first render has been forked.
   virtual int GetRendererSandboxStatus() const = 0;
 
+#if !defined(OS_BSD)
   // Adjust the OOM score of the given renderer's PID.  The allowed
   // range for the score is [0, 1000], where higher values are more
   // likely to be killed by the OOM killer.
   virtual void AdjustRendererOOMScore(base::ProcessHandle process_handle,
                                       int score) = 0;
+#endif
 };
 
 }  // namespace service_manager
