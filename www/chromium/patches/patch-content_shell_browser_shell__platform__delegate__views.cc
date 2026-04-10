$NetBSD: patch-content_shell_browser_shell__platform__delegate__views.cc,v 1.16 2026/04/10 17:31:55 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/shell/browser/shell_platform_delegate_views.cc.orig	2026-04-06 16:25:54.000000000 +0000
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
