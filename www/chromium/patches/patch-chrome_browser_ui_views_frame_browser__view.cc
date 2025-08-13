$NetBSD: patch-chrome_browser_ui_views_frame_browser__view.cc,v 1.5 2025/08/13 07:44:20 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/frame/browser_view.cc.orig	2025-07-29 22:51:44.000000000 +0000
+++ chrome/browser/ui/views/frame/browser_view.cc
@@ -2608,7 +2608,7 @@ void BrowserView::ToolbarSizeChanged(boo
 }
 
 void BrowserView::TabDraggingStatusChanged(bool is_dragging) {
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   GetContentsWebView()->SetFastResize(is_dragging);
   if (multi_contents_view_) {
     multi_contents_view_->GetInactiveContentsView()->SetFastResize(is_dragging);
@@ -6027,7 +6027,7 @@ void BrowserView::MaybeShowProfileSwitch
 }
 
 void BrowserView::MaybeShowSupervisedUserProfileSignInIPH() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!ShouldShowAvatarToolbarIPH()) {
     return;
   }
