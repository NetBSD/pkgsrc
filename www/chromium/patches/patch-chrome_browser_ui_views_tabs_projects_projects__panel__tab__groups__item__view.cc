$NetBSD: patch-chrome_browser_ui_views_tabs_projects_projects__panel__tab__groups__item__view.cc,v 1.8 2026/08/09 06:31:12 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/tabs/projects/projects_panel_tab_groups_item_view.cc.orig	2026-08-05 20:17:42.000000000 +0000
+++ chrome/browser/ui/views/tabs/projects/projects_panel_tab_groups_item_view.cc
@@ -247,7 +247,7 @@ void ProjectsPanelTabGroupsItemView::OnM
 
 void ProjectsPanelTabGroupsItemView::OnMouseExited(
     const ui::MouseEvent& event) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Bypasses the synchronous IsMouseHovered() check which can be stale on Linux
   // Wayland/X11 due to asynchronous cursor updates during mouse exit events.
   UpdateHoverStateForced(/*is_hovered=*/false);
