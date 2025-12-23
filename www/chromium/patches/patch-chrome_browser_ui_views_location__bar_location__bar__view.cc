$NetBSD: patch-chrome_browser_ui_views_location__bar_location__bar__view.cc,v 1.5 2025/12/23 13:22:15 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/location_bar/location_bar_view.cc.orig	2025-12-17 23:05:18.000000000 +0000
+++ chrome/browser/ui/views/location_bar/location_bar_view.cc
@@ -1768,7 +1768,7 @@ void LocationBarView::OnPopupStateChange
                      weak_factory_.GetWeakPtr()),
       base::Milliseconds(100));
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (new_state != OmniboxPopupState::kNone) {
     // Close any overlapping user education bubbles when any popup opens.
     // It's not great for promos to overlap the omnibox if the user opens the
