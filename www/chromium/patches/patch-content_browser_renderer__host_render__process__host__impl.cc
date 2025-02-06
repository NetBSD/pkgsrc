$NetBSD: patch-content_browser_renderer__host_render__process__host__impl.cc,v 1.1 2025/02/06 09:58:06 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/browser/renderer_host/render_process_host_impl.cc.orig	2025-02-01 12:26:17.880666258 +0100
+++ content/browser/renderer_host/render_process_host_impl.cc
@@ -220,7 +220,7 @@
 #include "third_party/blink/public/mojom/android_font_lookup/android_font_lookup.mojom.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include <sys/resource.h>
 
 #include "components/services/font/public/mojom/font_service.mojom.h"  // nogncheck
@@ -1083,7 +1083,7 @@ static constexpr size_t kUnknownPlatform
 // to indicate failure and std::numeric_limits<size_t>::max() to indicate
 // unlimited.
 size_t GetPlatformProcessLimit() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   struct rlimit limit;
   if (getrlimit(RLIMIT_NPROC, &limit) != 0)
     return kUnknownPlatformProcessLimit;
@@ -1260,7 +1260,7 @@ RenderProcessHostImpl::IOThreadHostImpl:
 
 void RenderProcessHostImpl::IOThreadHostImpl::SetPid(
     base::ProcessId child_pid) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   child_thread_type_switcher_.SetPid(child_pid);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 }
@@ -3264,7 +3264,7 @@ void RenderProcessHostImpl::AppendRender
             base::TimeTicks::UnixEpoch().since_origin().InMicroseconds()));
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Append `kDisableVideoCaptureUseGpuMemoryBuffer` flag if there is no support
   // for NV12 GPU memory buffer.
   if (switches::IsVideoCaptureUseGpuMemoryBufferEnabled() &&
@@ -3320,6 +3320,7 @@ void RenderProcessHostImpl::PropagateBro
       switches::kDisableSpeechAPI,
       switches::kDisableThreadedCompositing,
       switches::kDisableTouchDragDrop,
+      switches::kDisableUnveil,
       switches::kDisableV8IdleTasks,
       switches::kDisableVideoCaptureUseGpuMemoryBuffer,
       switches::kDisableWebGLImageChromium,
@@ -5102,7 +5103,7 @@ uint64_t RenderProcessHostImpl::GetPriva
   // - Win: https://crbug.com/707022 .
   uint64_t total_size = 0;
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   total_size = dump->platform_private_footprint->rss_anon_bytes +
                dump->platform_private_footprint->vm_swap_bytes;
 #elif BUILDFLAG(IS_APPLE)
