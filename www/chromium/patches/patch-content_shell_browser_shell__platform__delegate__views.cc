$NetBSD: patch-content_shell_browser_shell__platform__delegate__views.cc,v 1.7 2025/10/16 19:43:29 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/shell/browser/shell_platform_delegate_views.cc.orig	2025-10-13 21:41:26.000000000 +0000
+++ content/shell/browser/shell_platform_delegate_views.cc
@@ -373,7 +373,7 @@ void ShellPlatformDelegate::CreatePlatfo
       views::Widget::InitParams::NATIVE_WIDGET_OWNS_WIDGET);
   params.bounds = gfx::Rect(initial_size);
   params.delegate = delegate.release();
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   params.wm_class_class = "chromium-content_shell";
   params.wm_class_name = params.wm_class_class;
 #endif  // BUILDFLAG(IS_LINUX)
