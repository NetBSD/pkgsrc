$NetBSD: patch-chrome_browser_ui_views_location__bar_location__bar__view.cc,v 1.10 2026/04/21 15:21:11 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/location_bar/location_bar_view.cc.orig	2026-04-14 23:31:37.000000000 +0200
+++ chrome/browser/ui/views/location_bar/location_bar_view.cc
@@ -1873,7 +1873,7 @@ void LocationBarView::OnPopupStateChange
     }
   }
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (new_state != OmniboxPopupState::kNone) {
     // Close any overlapping user education bubbles when any popup opens.
     // It's not great for promos to overlap the omnibox if the user opens the
