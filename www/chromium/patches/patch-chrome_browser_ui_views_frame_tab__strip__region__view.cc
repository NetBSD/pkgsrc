$NetBSD: patch-chrome_browser_ui_views_frame_tab__strip__region__view.cc,v 1.1 2025/02/06 09:57:54 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/frame/tab_strip_region_view.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ chrome/browser/ui/views/frame/tab_strip_region_view.cc
@@ -205,7 +205,7 @@ TabStripRegionView::TabStripRegionView(s
 
     // TODO(crbug.com/40118868): Revisit the macro expression once build flag
     // switch of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
     // The New Tab Button can be middle-clicked on Linux.
     new_tab_button_->SetTriggerableEventFlags(
         new_tab_button_->GetTriggerableEventFlags() |
