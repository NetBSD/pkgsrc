$NetBSD: patch-chrome_browser_ui_views_frame_horizontal__tab__strip__region__view.cc,v 1.7 2026/09/02 13:13:25 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/frame/horizontal_tab_strip_region_view.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ chrome/browser/ui/views/frame/horizontal_tab_strip_region_view.cc
@@ -246,7 +246,7 @@ HorizontalTabStripRegionViewOld::Horizon
     new_tab_button_->GetViewAccessibility().SetName(
         l10n_util::GetStringUTF16(IDS_ACCNAME_NEWTAB));
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // On Linux, middle-clicking the New Tab Button triggers
     // paste and navigate, either to URLs or to search queries.
     new_tab_button_->SetTriggerableEventFlags(
