$NetBSD: patch-chrome_browser_ui_views_frame_multi__contents__view__drop__target__controller.cc,v 1.17 2026/10/23 15:05:21 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/frame/multi_contents_view_drop_target_controller.cc.orig	2026-10-19 20:07:21.000000000 +0000
+++ chrome/browser/ui/views/frame/multi_contents_view_drop_target_controller.cc
@@ -57,7 +57,7 @@ int MultiContentsViewDropTargetControlle
   return
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN)
       32;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       50;
 #else
       0;
