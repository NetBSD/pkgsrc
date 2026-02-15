$NetBSD: patch-chrome_browser_ui_views_tabs_tab__style__views.cc,v 1.15 2026/02/15 09:04:00 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/tabs/tab_style_views.cc.orig	2026-02-03 22:07:10.000000000 +0000
+++ chrome/browser/ui/views/tabs/tab_style_views.cc
@@ -557,7 +557,7 @@ float TabStyleViewsImpl::GetCurrentActiv
   if (!IsHoverAnimationActive()) {
     return base_opacity;
   }
-  return std::lerp(base_opacity, GetHoverOpacity(), GetHoverAnimationValue());
+  return std::lerp(base_opacity, GetHoverOpacity(), static_cast<float>(GetHoverAnimationValue()));
 }
 
 bool TabStyleViewsImpl::IsApparentlyActive() const {
