$NetBSD: patch-src_3rdparty_chromium_content_browser_renderer__host_render__process__host__impl.cc,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/content/browser/renderer_host/render_process_host_impl.cc.orig	2020-11-07 01:22:36.000000000 +0000
+++ src/3rdparty/chromium/content/browser/renderer_host/render_process_host_impl.cc
@@ -240,7 +240,7 @@
 #include "content/browser/gpu/gpu_data_manager_impl.h"
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include <sys/resource.h>
 #include <sys/time.h>
 
@@ -1204,7 +1204,7 @@ static constexpr size_t kUnknownPlatform
 // to indicate failure and std::numeric_limits<size_t>::max() to indicate
 // unlimited.
 size_t GetPlatformProcessLimit() {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   struct rlimit limit;
   if (getrlimit(RLIMIT_NPROC, &limit) != 0)
     return kUnknownPlatformProcessLimit;
@@ -1303,7 +1303,7 @@ void RenderProcessHostImpl::IOThreadHost
       return;
   }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   if (auto font_receiver = receiver.As<font_service::mojom::FontService>()) {
     ConnectToFontService(std::move(font_receiver));
     return;
@@ -1719,7 +1719,7 @@ bool RenderProcessHostImpl::Init() {
   renderer_prefix =
       browser_command_line.GetSwitchValueNative(switches::kRendererCmdPrefix);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   int flags = renderer_prefix.empty() ? ChildProcessHost::CHILD_ALLOW_SELF
                                       : ChildProcessHost::CHILD_NORMAL;
 #elif defined(OS_MACOSX)
@@ -3631,7 +3631,7 @@ void RenderProcessHostImpl::OnChannelCon
     for (auto& observer : observers_)
       observer.RenderProcessReady(this);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     // Provide /proc/{renderer pid}/status and statm files for
     // MemoryUsageMonitor in blink.
     ProvideStatusFileForRenderer();
@@ -4899,7 +4899,7 @@ void RenderProcessHostImpl::OnProcessLau
     for (auto& observer : observers_)
       observer.RenderProcessReady(this);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     // Provide /proc/{renderer pid}/status and statm files for
     // MemoryUsageMonitor in blink.
     ProvideStatusFileForRenderer();
@@ -5072,7 +5072,7 @@ void RenderProcessHost::InterceptBindHos
   GetBindHostReceiverInterceptor() = std::move(callback);
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 void RenderProcessHostImpl::ProvideStatusFileForRenderer() {
   // We use ScopedAllowBlocking, because opening /proc/{pid}/status and
   // /proc/{pid}/statm is not blocking call.
