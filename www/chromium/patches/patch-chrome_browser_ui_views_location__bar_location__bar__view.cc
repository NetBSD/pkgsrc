$NetBSD: patch-chrome_browser_ui_views_location__bar_location__bar__view.cc,v 1.6 2026/01/19 16:14:11 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/location_bar/location_bar_view.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ chrome/browser/ui/views/location_bar/location_bar_view.cc
@@ -1785,7 +1785,7 @@ void LocationBarView::OnPopupStateChange
                      weak_factory_.GetWeakPtr()),
       base::Milliseconds(100));
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (new_state != OmniboxPopupState::kNone) {
     // Close any overlapping user education bubbles when any popup opens.
     // It's not great for promos to overlap the omnibox if the user opens the
