$NetBSD: patch-chrome_browser_ui_views_frame_custom__corners__background.cc,v 1.1 2026/03/14 12:40:28 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/frame/custom_corners_background.cc.orig	2026-03-11 22:12:25.000000000 +0000
+++ chrome/browser/ui/views/frame/custom_corners_background.cc
@@ -117,7 +117,7 @@ CustomCornersBackground::Corner CustomCo
   } else {
     corner.type = CornerType::kSquare;
   }
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (auto* const widget = browser_view().browser_widget()) {
     if (auto* const frame = widget->GetFrameView()) {
       const auto rrect = frame->GetRestoredClipRegion();
