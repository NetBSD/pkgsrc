$NetBSD: patch-chrome_browser_ui_views_frame_layout_browser__view__app__layout__impl.cc,v 1.2 2026/02/15 09:04:00 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/frame/layout/browser_view_app_layout_impl.cc.orig	2026-02-03 22:07:10.000000000 +0000
+++ chrome/browser/ui/views/frame/layout/browser_view_app_layout_impl.cc
@@ -371,7 +371,7 @@ void BrowserViewAppLayoutImpl::DoPostLay
     label.SetSubpixelRenderingEnabled(false);
     label.SetHorizontalAlignment(gfx::ALIGN_LEFT);
     label.SetAutoColorReadabilityEnabled(false);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     label.SetSubpixelRenderingEnabled(false);
     label.SetHorizontalAlignment(gfx::ALIGN_LEFT);
 #endif
