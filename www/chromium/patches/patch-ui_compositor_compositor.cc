$NetBSD: patch-ui_compositor_compositor.cc,v 1.15 2026/02/15 09:04:13 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/compositor/compositor.cc.orig	2026-02-03 22:07:10.000000000 +0000
+++ ui/compositor/compositor.cc
@@ -990,7 +990,7 @@ void Compositor::OnResume() {
     obs.ResetIfActive();
 }
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(IS_OZONE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(IS_OZONE_X11)
 void Compositor::OnCompleteSwapWithNewSize(const gfx::Size& size) {
   observer_list_.Notify(
       &CompositorObserver::OnCompositingCompleteSwapWithNewSize, this, size);
