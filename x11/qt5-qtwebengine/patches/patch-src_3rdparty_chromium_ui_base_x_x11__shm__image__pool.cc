$NetBSD: patch-src_3rdparty_chromium_ui_base_x_x11__shm__image__pool.cc,v 1.1 2021/08/03 21:04:36 markd Exp $

--- src/3rdparty/chromium/ui/base/x/x11_shm_image_pool.cc.orig	2020-07-15 18:56:49.000000000 +0000
+++ src/3rdparty/chromium/ui/base/x/x11_shm_image_pool.cc
@@ -16,6 +16,7 @@
 #include "base/environment.h"
 #include "base/location.h"
 #include "base/strings/string_util.h"
+#include "base/system/sys_info.h"
 #include "base/threading/thread_task_runner_handle.h"
 #include "build/build_config.h"
 #include "net/base/url_util.h"
@@ -44,10 +45,14 @@ constexpr float kShmResizeShrinkThreshol
     1.0f / (kShmResizeThreshold * kShmResizeThreshold);
 
 std::size_t MaxShmSegmentSizeImpl() {
+#if defined(OS_BSD)
+  return base::SysInfo::MaxSharedMemorySize();
+#else
   struct shminfo info;
   if (shmctl(0, IPC_INFO, reinterpret_cast<struct shmid_ds*>(&info)) == -1)
     return 0;
   return info.shmmax;
+#endif
 }
 
 std::size_t MaxShmSegmentSize() {
@@ -201,7 +206,7 @@ bool XShmImagePool::Resize(const gfx::Si
         shmctl(state.shminfo_.shmid, IPC_RMID, nullptr);
         return false;
       }
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
       // On Linux, a shmid can still be attached after IPC_RMID if otherwise
       // kept alive.  Detach before XShmAttach to prevent a memory leak in case
       // the process dies.
@@ -211,7 +216,7 @@ bool XShmImagePool::Resize(const gfx::Si
       if (!XShmAttach(display_, &state.shminfo_))
         return false;
       state.shmem_attached_to_server_ = true;
-#if !defined(OS_LINUX)
+#if !defined(OS_LINUX) && !defined(OS_BSD)
       // The Linux-specific shmctl behavior above may not be portable, so we're
       // forced to do IPC_RMID after the server has attached to the segment.
       // XShmAttach is asynchronous, so we must also sync.
