$NetBSD: patch-chrome_browser_ui_views_tabs_common_tab__group__header__view.cc,v 1.5 2026/10/02 11:43:25 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/tabs/common/tab_group_header_view.cc.orig	2026-09-22 00:09:16.000000000 +0000
+++ chrome/browser/ui/views/tabs/common/tab_group_header_view.cc
@@ -392,7 +392,7 @@ void TabGroupHeaderView::OnMouseEntered(
 }
 
 void TabGroupHeaderView::OnMouseExited(const ui::MouseEvent& event) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Bypasses the synchronous IsMouseHovered() check which can be stale on Linux
   // Wayland/X11 due to asynchronous cursor updates during mouse exit events.
   SetEditorBubbleButtonVisibilityOnHover(/*is_hovered=*/false);
