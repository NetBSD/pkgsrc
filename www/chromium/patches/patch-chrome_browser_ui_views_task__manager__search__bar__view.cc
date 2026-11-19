$NetBSD: patch-chrome_browser_ui_views_task__manager__search__bar__view.cc,v 1.32 2026/11/19 19:45:56 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/task_manager_search_bar_view.cc.orig	2026-11-11 21:01:38.000000000 +0000
+++ chrome/browser/ui/views/task_manager_search_bar_view.cc
@@ -28,7 +28,7 @@ namespace task_manager {
 namespace {
 
 ui::ColorId GetTextfieldPlaceholderTextColor() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return kColorTaskManagerSearchBarPlaceholderText;
 #else
   return ui::kColorTextfieldForegroundPlaceholder;
