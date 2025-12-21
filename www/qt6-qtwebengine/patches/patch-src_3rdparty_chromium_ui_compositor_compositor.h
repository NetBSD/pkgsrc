$NetBSD: patch-src_3rdparty_chromium_ui_compositor_compositor.h,v 1.1 2025/12/21 09:38:47 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/ui/compositor/compositor.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/ui/compositor/compositor.h
@@ -457,7 +457,7 @@ class COMPOSITOR_EXPORT Compositor : pub
   // base::PowerSuspendObserver:
   void OnResume() override;
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(IS_OZONE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(IS_OZONE_X11)
   void OnCompleteSwapWithNewSize(const gfx::Size& size);
 #endif  // BUILDFLAG(IS_LINUX) && BUILDFLAG(IS_OZONE_X11)
 
