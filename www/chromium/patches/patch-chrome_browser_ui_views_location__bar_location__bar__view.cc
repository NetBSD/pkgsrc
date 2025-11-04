$NetBSD: patch-chrome_browser_ui_views_location__bar_location__bar__view.cc,v 1.1 2025/11/04 14:55:35 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/location_bar/location_bar_view.cc.orig	2025-10-24 16:42:30.000000000 +0000
+++ chrome/browser/ui/views/location_bar/location_bar_view.cc
@@ -527,7 +527,7 @@ bool LocationBarView::IsInitialized() co
 }
 
 void LocationBarView::OnPopupOpened() {
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // It's not great for promos to overlap the omnibox if the user opens the
   // drop-down after showing the promo. This especially causes issues on Mac and
   // Linux due to z-order/rendering issues, see crbug.com/1225046 and
