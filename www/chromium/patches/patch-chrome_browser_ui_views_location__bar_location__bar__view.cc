$NetBSD: patch-chrome_browser_ui_views_location__bar_location__bar__view.cc,v 1.15 2026/07/08 13:42:18 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/location_bar/location_bar_view.cc.orig	2026-07-06 22:58:46.000000000 +0000
+++ chrome/browser/ui/views/location_bar/location_bar_view.cc
@@ -1929,7 +1929,7 @@ void LocationBarView::OnPopupStateChange
     }
   }
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (new_state != OmniboxPopupState::kNone) {
     // Close any overlapping user education bubbles when any popup opens.
     // It's not great for promos to overlap the omnibox if the user opens the
