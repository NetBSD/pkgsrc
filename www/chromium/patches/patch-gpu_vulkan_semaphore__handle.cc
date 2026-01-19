$NetBSD: patch-gpu_vulkan_semaphore__handle.cc,v 1.14 2026/01/19 16:14:16 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- gpu/vulkan/semaphore_handle.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ gpu/vulkan/semaphore_handle.cc
@@ -39,7 +39,7 @@ SemaphoreHandle::SemaphoreHandle(gfx::Gp
   // https://fuchsia.dev/reference/fidl/fuchsia.ui.scenic.
   Init(VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_ZIRCON_EVENT_BIT_FUCHSIA,
        fence_handle.Release());
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   Init(VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_SYNC_FD_BIT_KHR,
        fence_handle.Release());
 #elif BUILDFLAG(IS_POSIX)
@@ -64,7 +64,7 @@ gfx::GpuFenceHandle SemaphoreHandle::ToG
   // VkSemaphore, which can then be used to submit present work, see
   // https://fuchsia.dev/reference/fidl/fuchsia.ui.scenic.
   fence_handle.Adopt(TakeHandle());
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   if (type_ == VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_SYNC_FD_BIT_KHR) {
     fence_handle.Adopt(TakeHandle());
   } else {
