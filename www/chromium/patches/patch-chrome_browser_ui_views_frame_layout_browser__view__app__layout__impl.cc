$NetBSD: patch-chrome_browser_ui_views_frame_layout_browser__view__app__layout__impl.cc,v 1.6 2026/05/10 15:29:52 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/frame/layout/browser_view_app_layout_impl.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ chrome/browser/ui/views/frame/layout/browser_view_app_layout_impl.cc
@@ -404,7 +404,7 @@ void BrowserViewAppLayoutImpl::DoPostLay
 #elif BUILDFLAG(IS_WIN)
     label.SetSubpixelRenderingEnabled(false);
     label.SetAutoColorReadabilityEnabled(false);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     label.SetSubpixelRenderingEnabled(false);
 #endif
   }
