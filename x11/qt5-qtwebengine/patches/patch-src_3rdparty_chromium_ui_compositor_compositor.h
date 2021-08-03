$NetBSD: patch-src_3rdparty_chromium_ui_compositor_compositor.h,v 1.1 2021/08/03 21:04:36 markd Exp $

--- src/3rdparty/chromium/ui/compositor/compositor.h.orig	2020-11-07 01:22:36.000000000 +0000
+++ src/3rdparty/chromium/ui/compositor/compositor.h
@@ -341,7 +341,7 @@ class COMPOSITOR_EXPORT Compositor : pub
   void OnFirstSurfaceActivation(const viz::SurfaceInfo& surface_info) override;
   void OnFrameTokenChanged(uint32_t frame_token) override;
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   void OnCompleteSwapWithNewSize(const gfx::Size& size);
 #endif
 
