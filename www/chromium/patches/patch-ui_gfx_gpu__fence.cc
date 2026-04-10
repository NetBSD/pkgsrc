$NetBSD: patch-ui_gfx_gpu__fence.cc,v 1.1 2026/04/10 17:32:02 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/gfx/gpu_fence.cc.orig	2026-04-06 16:25:54.000000000 +0000
+++ ui/gfx/gpu_fence.cc
@@ -14,6 +14,10 @@
 #include <sync/sync.h>
 #endif
 
+#if BUILDFLAG(IS_BSD)
+#include <poll.h>
+#endif
+
 namespace gfx {
 
 GpuFence::GpuFence(GpuFenceHandle fence_handle)
@@ -49,6 +53,12 @@ void GpuFence::Wait() {
   if (sync_wait(fence_handle_.Peek(), kInfiniteSyncWaitTimeout) < 0) {
     LOG(FATAL) << "Failed while waiting for gpu fence fd";
   }
+#elif BUILDFLAG(IS_BSD)
+  int fd = fence_handle_.Peek();
+  if (fd >= 0) {
+    struct pollfd fds = {fd, POLLIN, 0};
+    poll(&fds, 1, -1);
+  }
 #else
   NOTREACHED();
 #endif
@@ -63,6 +73,9 @@ GpuFence::FenceStatus GpuFence::GetStatu
   auto info =
       std::unique_ptr<sync_fence_info_data, void (*)(sync_fence_info_data*)>{
           sync_fence_info(fd), sync_fence_info_free};
+#elif BUILDFLAG(IS_BSD)
+  // sync_fence_info is not available on FreeBSD.
+  return FenceStatus::kInvalid;
 #else   // !BUILDFLAG(IS_CHROMEOS_DEVICE)
   auto info =
       std::unique_ptr<struct sync_file_info, void (*)(struct sync_file_info*)>{
