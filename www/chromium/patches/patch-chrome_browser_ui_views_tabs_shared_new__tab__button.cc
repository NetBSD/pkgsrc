$NetBSD: patch-chrome_browser_ui_views_tabs_shared_new__tab__button.cc,v 1.1 2026/09/29 07:42:51 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/tabs/shared/new_tab_button.cc.orig	2026-09-22 00:09:16.000000000 +0000
+++ chrome/browser/ui/views/tabs/shared/new_tab_button.cc
@@ -45,7 +45,7 @@ NewTabButton::NewTabButton(BrowserWindow
 
   set_context_menu_controller(this);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // On Linux, middle-clicking the New Tab Button triggers
   // paste and navigate, either to URLs or to search queries.
   SetTriggerableEventFlags(GetTriggerableEventFlags() |
@@ -116,7 +116,7 @@ void NewTabButton::SetMiddleClickCallbac
 }
 
 void NewTabButton::NotifyClick(const ui::Event& event) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (event.IsMouseEvent()) {
     const ui::MouseEvent& mouse = static_cast<const ui::MouseEvent&>(event);
     if (mouse.IsOnlyMiddleMouseButton()) {
