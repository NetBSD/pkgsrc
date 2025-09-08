$NetBSD: patch-chrome_browser_ui_views_chrome__views__delegate.h,v 1.6 2025/09/08 13:24:20 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/chrome_views_delegate.h.orig	2025-08-29 18:50:09.000000000 +0000
+++ chrome/browser/ui/views/chrome_views_delegate.h
@@ -52,7 +52,7 @@ class ChromeViewsDelegate : public views
                              base::OnceClosure callback) override;
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool WindowManagerProvidesTitleBar(bool maximized) override;
   gfx::ImageSkia* GetDefaultWindowIcon() const override;
 #endif
