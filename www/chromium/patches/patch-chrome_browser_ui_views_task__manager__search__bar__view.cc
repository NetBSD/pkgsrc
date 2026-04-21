$NetBSD: patch-chrome_browser_ui_views_task__manager__search__bar__view.cc,v 1.17 2026/04/21 15:21:11 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/task_manager_search_bar_view.cc.orig	2026-04-14 23:31:37.000000000 +0200
+++ chrome/browser/ui/views/task_manager_search_bar_view.cc
@@ -29,7 +29,7 @@ TaskManagerSearchBarView::TaskManagerSea
     const gfx::Insets& margins,
     Delegate& delegate)
     : delegate_(delegate)
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       ,
       textfield_placeholder_color_id_(kColorTaskManagerSearchBarPlaceholderText)
 #endif
