$NetBSD: patch-content_browser_zygote__host_zygote__host__impl__linux.h,v 1.1 2025/02/06 09:58:07 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/browser/zygote_host/zygote_host_impl_linux.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ content/browser/zygote_host/zygote_host_impl_linux.h
@@ -47,12 +47,14 @@ class CONTENT_EXPORT ZygoteHostImpl : pu
                      base::ScopedFD* control_fd,
                      base::FileHandleMappingVector additional_remapped_fds);
 
+#if !BUILDFLAG(IS_BSD)
   void AdjustRendererOOMScore(base::ProcessHandle process_handle,
                               int score) override;
 #if BUILDFLAG(IS_CHROMEOS)
   void ReinitializeLogging(uint32_t logging_dest,
                            base::PlatformFile log_file_fd) override;
 #endif  // BUILDFLAG(IS_CHROMEOS)
+#endif
 
   bool HasZygote() { return !zygote_pids_.empty(); }
 
@@ -67,9 +69,11 @@ class CONTENT_EXPORT ZygoteHostImpl : pu
 
   int renderer_sandbox_status_;
 
+#if !BUILDFLAG(IS_BSD)
   bool use_namespace_sandbox_;
   bool use_suid_sandbox_;
   bool use_suid_sandbox_for_adj_oom_score_;
+#endif
   std::string sandbox_binary_;
 
   // This lock protects the |zygote_pids_| set.
