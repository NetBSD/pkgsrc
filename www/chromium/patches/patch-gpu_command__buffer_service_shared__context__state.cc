$NetBSD: patch-gpu_command__buffer_service_shared__context__state.cc,v 1.31 2026/10/23 15:05:28 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- gpu/command_buffer/service/shared_context_state.cc.orig	2026-10-19 20:07:21.000000000 +0000
+++ gpu/command_buffer/service/shared_context_state.cc
@@ -68,7 +68,7 @@
 #include "gpu/vulkan/vulkan_implementation.h"
 #include "gpu/vulkan/vulkan_util.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 #include "gpu/command_buffer/service/external_semaphore_pool.h"
 #endif
 
@@ -307,7 +307,7 @@ SharedContextState::SharedContextState(
 #endif
   ) {
     if (vk_context_provider_) {
-#if BUILDFLAG(ENABLE_VULKAN) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA))
+#if BUILDFLAG(ENABLE_VULKAN) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD))
       external_semaphore_pool_ = std::make_unique<ExternalSemaphorePool>(this);
 #endif
     }
@@ -347,7 +347,7 @@ SharedContextState::~SharedContextState(
     UnbindCacheFromCurrentOpenGLContext();
   }
 
-#if BUILDFLAG(ENABLE_VULKAN) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA))
+#if BUILDFLAG(ENABLE_VULKAN) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD))
   external_semaphore_pool_.reset();
 #endif
 
