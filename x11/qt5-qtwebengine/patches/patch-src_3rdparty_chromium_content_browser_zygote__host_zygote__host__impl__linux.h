$NetBSD: patch-src_3rdparty_chromium_content_browser_zygote__host_zygote__host__impl__linux.h,v 1.1 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/content/browser/zygote_host/zygote_host_impl_linux.h.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/content/browser/zygote_host/zygote_host_impl_linux.h
@@ -42,8 +42,10 @@ class CONTENT_EXPORT ZygoteHostImpl : pu
                      base::ScopedFD* control_fd,
                      base::FileHandleMappingVector additional_remapped_fds);
 
+#if !defined(OS_BSD)
   void AdjustRendererOOMScore(base::ProcessHandle process_handle,
                               int score) override;
+#endif
   bool HasZygote() { return !zygote_pids_.empty(); }
 
  private:
@@ -57,9 +59,11 @@ class CONTENT_EXPORT ZygoteHostImpl : pu
 
   int renderer_sandbox_status_;
 
+#if !defined(OS_BSD)
   bool use_namespace_sandbox_;
   bool use_suid_sandbox_;
   bool use_suid_sandbox_for_adj_oom_score_;
+#endif
   std::string sandbox_binary_;
 
   // This lock protects the |zygote_pids_| set.
