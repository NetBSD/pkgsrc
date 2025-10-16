$NetBSD: patch-chrome_browser_ui_views_frame_tab__strip__region__view.cc,v 1.8 2025/10/16 19:43:24 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/frame/tab_strip_region_view.cc.orig	2025-10-13 21:41:26.000000000 +0000
+++ chrome/browser/ui/views/frame/tab_strip_region_view.cc
@@ -304,7 +304,7 @@ TabStripRegionView::TabStripRegionView(s
     new_tab_button_->GetViewAccessibility().SetName(
         l10n_util::GetStringUTF16(IDS_ACCNAME_NEWTAB));
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       // The New Tab Button can be middle-clicked on Linux.
       new_tab_button_->SetTriggerableEventFlags(
           new_tab_button_->GetTriggerableEventFlags() |
