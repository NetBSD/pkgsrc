$NetBSD: patch-gpu_command__buffer_service_shared__context__state.h,v 1.19 2026/05/10 15:29:59 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- gpu/command_buffer/service/shared_context_state.h.orig	2026-04-28 23:05:57.000000000 +0200
+++ gpu/command_buffer/service/shared_context_state.h
@@ -242,7 +242,7 @@ class GPU_GLES2_EXPORT SharedContextStat
     return &memory_type_tracker_;
   }
 #if BUILDFLAG(ENABLE_VULKAN) && \
-    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_WIN))
+    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD))
   ExternalSemaphorePool* external_semaphore_pool() {
     return external_semaphore_pool_.get();
   }
@@ -412,7 +412,7 @@ class GPU_GLES2_EXPORT SharedContextStat
   bool disable_check_reset_status_throttling_for_test_ = false;
 
 #if BUILDFLAG(ENABLE_VULKAN) && \
-    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_WIN))
+    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD))
   std::unique_ptr<ExternalSemaphorePool> external_semaphore_pool_;
 #endif
 
