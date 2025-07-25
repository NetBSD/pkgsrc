$NetBSD: patch-chrome_browser_ui_views_tabs_tab__style__views.cc,v 1.4 2025/07/25 16:17:13 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/tabs/tab_style_views.cc.orig	2025-07-21 19:32:31.000000000 +0000
+++ chrome/browser/ui/views/tabs/tab_style_views.cc
@@ -573,7 +573,7 @@ float TabStyleViewsImpl::GetCurrentActiv
   if (!IsHoverAnimationActive()) {
     return base_opacity;
   }
-  return std::lerp(base_opacity, GetHoverOpacity(), GetHoverAnimationValue());
+  return std::lerp(base_opacity, GetHoverOpacity(), static_cast<float>(GetHoverAnimationValue()));
 }
 
 TabActive TabStyleViewsImpl::GetApparentActiveState() const {
