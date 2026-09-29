$NetBSD: patch-chrome_browser_ui_views_tabs_vertical_vertical__tab__strip__focus__swipe__controller.h,v 1.1 2026/09/29 07:42:51 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/tabs/vertical/vertical_tab_strip_focus_swipe_controller.h.orig	2026-09-22 00:09:16.000000000 +0000
+++ chrome/browser/ui/views/tabs/vertical/vertical_tab_strip_focus_swipe_controller.h
@@ -31,7 +31,7 @@ class VerticalTabStripFocusSwipeControll
   ~VerticalTabStripFocusSwipeController() override;
 
   // ui::EventHandler:
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   void OnMouseEvent(ui::MouseEvent* event) override;
 #elif BUILDFLAG(IS_MAC)
   void OnScrollEvent(ui::ScrollEvent* event) override;
