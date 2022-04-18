$NetBSD: patch-src_3rdparty_chromium_content_browser_renderer__host_render__message__filter.cc,v 1.2 2022/04/18 11:18:18 adam Exp $

--- src/3rdparty/chromium/content/browser/renderer_host/render_message_filter.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/content/browser/renderer_host/render_message_filter.cc
@@ -70,7 +70,7 @@
 #if defined(OS_MAC)
 #include "ui/accelerated_widget_mac/window_resize_helper_mac.h"
 #endif
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "base/linux_util.h"
 #include "base/threading/platform_thread.h"
 #endif
@@ -117,7 +117,7 @@ void RenderMessageFilter::GenerateRoutin
   std::move(callback).Run(render_widget_helper_->GetNextRoutingID());
 }
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 void RenderMessageFilter::SetThreadPriorityOnFileThread(
     base::PlatformThreadId ns_tid,
     base::ThreadPriority priority) {
@@ -138,7 +138,7 @@ void RenderMessageFilter::SetThreadPrior
 }
 #endif
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 void RenderMessageFilter::SetThreadPriority(int32_t ns_tid,
                                             base::ThreadPriority priority) {
   constexpr base::TaskTraits kTraits = {
