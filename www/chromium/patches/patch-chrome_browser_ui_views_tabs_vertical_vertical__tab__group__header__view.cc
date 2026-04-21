$NetBSD: patch-chrome_browser_ui_views_tabs_vertical_vertical__tab__group__header__view.cc,v 1.2 2026/04/21 15:21:11 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/tabs/vertical/vertical_tab_group_header_view.cc.orig	2026-04-14 23:31:37.000000000 +0200
+++ chrome/browser/ui/views/tabs/vertical/vertical_tab_group_header_view.cc
@@ -293,7 +293,7 @@ void VerticalTabGroupHeaderView::OnMouse
 }
 
 void VerticalTabGroupHeaderView::OnMouseExited(const ui::MouseEvent& event) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Bypasses the synchronous IsMouseHovered() check which can be stale on Linux
   // Wayland/X11 due to asynchronous cursor updates during mouse exit events.
   SetEditorBubbleButtonVisibilityOnHover(/*is_hovered=*/false);
