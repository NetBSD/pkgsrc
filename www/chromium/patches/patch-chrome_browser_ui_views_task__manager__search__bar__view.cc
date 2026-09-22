$NetBSD: patch-chrome_browser_ui_views_task__manager__search__bar__view.cc,v 1.25 2026/09/22 13:41:22 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/task_manager_search_bar_view.cc.orig	2026-09-14 22:17:16.000000000 +0000
+++ chrome/browser/ui/views/task_manager_search_bar_view.cc
@@ -28,7 +28,7 @@ namespace task_manager {
 namespace {
 
 ui::ColorId GetTextfieldPlaceholderTextColor() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return kColorTaskManagerSearchBarPlaceholderText;
 #else
   return ui::kColorTextfieldForegroundPlaceholder;
