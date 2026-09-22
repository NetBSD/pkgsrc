$NetBSD: patch-content_browser_compositor_viz__process__transport__factory.cc,v 1.26 2026/09/22 13:41:25 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/browser/compositor/viz_process_transport_factory.cc.orig	2026-09-14 22:17:16.000000000 +0000
+++ content/browser/compositor/viz_process_transport_factory.cc
@@ -101,7 +101,7 @@ class HostDisplayClient : public viz::Ho
   HostDisplayClient& operator=(const HostDisplayClient&) = delete;
 
   // viz::HostDisplayClient:
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(SUPPORTS_OZONE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(SUPPORTS_OZONE_X11)
   void DidCompleteSwapWithNewSize(const gfx::Size& size) override {
     compositor_->OnCompleteSwapWithNewSize(size);
   }
