$NetBSD: patch-ui_compositor_compositor__observer.h,v 1.13 2025/12/23 13:22:26 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/compositor/compositor_observer.h.orig	2025-12-17 23:05:18.000000000 +0000
+++ ui/compositor/compositor_observer.h
@@ -56,7 +56,7 @@ class COMPOSITOR_EXPORT CompositorObserv
   // Called when a child of the compositor is resizing.
   virtual void OnCompositingChildResizing(Compositor* compositor) {}
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(IS_OZONE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(IS_OZONE_X11)
   // Called when a swap with new size is completed.
   virtual void OnCompositingCompleteSwapWithNewSize(ui::Compositor* compositor,
                                                     const gfx::Size& size) {}
