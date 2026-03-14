$NetBSD: patch-chrome_browser_ui_views_task__manager__search__bar__view.cc,v 1.15 2026/03/14 12:40:28 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/task_manager_search_bar_view.cc.orig	2026-03-11 22:12:25.000000000 +0000
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
