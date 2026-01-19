$NetBSD: patch-chrome_browser_ui_views_frame_opaque__browser__frame__view__layout__delegate.h,v 1.14 2026/01/19 16:14:11 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/frame/opaque_browser_frame_view_layout_delegate.h.orig	2026-01-07 00:50:30.000000000 +0000
+++ chrome/browser/ui/views/frame/opaque_browser_frame_view_layout_delegate.h
@@ -9,7 +9,7 @@
 
 #include "build/build_config.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/base/ui_base_types.h"
 #endif
 
@@ -88,7 +88,7 @@ class OpaqueBrowserFrameViewLayoutDelega
   // Returns true if a client-side shadow should be drawn for restored windows.
   virtual bool ShouldDrawRestoredFrameShadow() const = 0;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Returns whether the window is in a tiled state.
   virtual bool IsTiled() const = 0;
 #endif
