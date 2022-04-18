$NetBSD: patch-src_3rdparty_chromium_content_browser_renderer__host_render__process__host__impl.cc,v 1.2 2022/04/18 11:18:18 adam Exp $

--- src/3rdparty/chromium/content/browser/renderer_host/render_process_host_impl.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/content/browser/renderer_host/render_process_host_impl.cc
@@ -234,7 +234,7 @@
 #include "third_party/blink/public/mojom/android_font_lookup/android_font_lookup.mojom.h"
 #endif
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include <sys/resource.h>
 #include <sys/time.h>
 
@@ -1232,7 +1232,7 @@ static constexpr size_t kUnknownPlatform
 // to indicate failure and std::numeric_limits<size_t>::max() to indicate
 // unlimited.
 size_t GetPlatformProcessLimit() {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   struct rlimit limit;
   if (getrlimit(RLIMIT_NPROC, &limit) != 0)
     return kUnknownPlatformProcessLimit;
@@ -1325,7 +1325,7 @@ void RenderProcessHostImpl::IOThreadHost
       return;
   }
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   if (auto font_receiver = receiver.As<font_service::mojom::FontService>()) {
     ConnectToFontService(std::move(font_receiver));
     return;
@@ -1751,7 +1751,7 @@ bool RenderProcessHostImpl::Init() {
   renderer_prefix =
       browser_command_line.GetSwitchValueNative(switches::kRendererCmdPrefix);
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   int flags = renderer_prefix.empty() ? ChildProcessHost::CHILD_ALLOW_SELF
                                       : ChildProcessHost::CHILD_NORMAL;
 #elif defined(OS_MAC)
@@ -3746,7 +3746,7 @@ void RenderProcessHostImpl::OnChannelCon
     for (auto& observer : observers_)
       observer.RenderProcessReady(this);
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
     // Provide /proc/{renderer pid}/status and statm files for
     // MemoryUsageMonitor in blink.
     ProvideStatusFileForRenderer();
@@ -5059,7 +5059,7 @@ void RenderProcessHostImpl::OnProcessLau
     for (auto& observer : observers_)
       observer.RenderProcessReady(this);
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
     // Provide /proc/{renderer pid}/status and statm files for
     // MemoryUsageMonitor in blink.
     ProvideStatusFileForRenderer();
@@ -5241,7 +5241,7 @@ void RenderProcessHost::InterceptBindHos
   GetBindHostReceiverInterceptor() = std::move(callback);
 }
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 void RenderProcessHostImpl::ProvideStatusFileForRenderer() {
   // We use ScopedAllowBlocking, because opening /proc/{pid}/status and
   // /proc/{pid}/statm is not blocking call.
