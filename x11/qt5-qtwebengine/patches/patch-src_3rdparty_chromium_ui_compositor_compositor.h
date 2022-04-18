$NetBSD: patch-src_3rdparty_chromium_ui_compositor_compositor.h,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/ui/compositor/compositor.h.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/ui/compositor/compositor.h
@@ -366,7 +366,7 @@ class COMPOSITOR_EXPORT Compositor : pub
   void StopThroughtputTracker(TrackerId tracker_id) override;
   void CancelThroughtputTracker(TrackerId tracker_id) override;
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   void OnCompleteSwapWithNewSize(const gfx::Size& size);
 #endif
 
