$NetBSD: patch-chrome_browser_ui_views_task__manager__search__bar__view.cc,v 1.6 2025/09/12 16:02:24 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/task_manager_search_bar_view.cc.orig	2025-09-08 23:21:33.000000000 +0000
+++ chrome/browser/ui/views/task_manager_search_bar_view.cc
@@ -27,7 +27,7 @@ TaskManagerSearchBarView::TaskManagerSea
     const gfx::Insets& margins,
     Delegate& delegate)
     : delegate_(delegate)
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       ,
       textfield_placeholder_color_id_(kColorTaskManagerSearchBarPlaceholderText)
 #endif
