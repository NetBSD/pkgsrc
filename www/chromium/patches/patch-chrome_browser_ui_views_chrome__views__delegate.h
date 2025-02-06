$NetBSD: patch-chrome_browser_ui_views_chrome__views__delegate.h,v 1.1 2025/02/06 09:57:53 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/chrome_views_delegate.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ chrome/browser/ui/views/chrome_views_delegate.h
@@ -61,11 +61,11 @@ class ChromeViewsDelegate : public views
                              base::OnceClosure callback) override;
 // TODO(crbug.com/40118868): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   bool WindowManagerProvidesTitleBar(bool maximized) override;
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   gfx::ImageSkia* GetDefaultWindowIcon() const override;
 #endif
 
