$NetBSD: patch-chrome_browser_ui_views_frame_browser__view.cc,v 1.10 2025/11/20 08:36:09 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/frame/browser_view.cc.orig	2025-11-14 20:31:45.000000000 +0000
+++ chrome/browser/ui/views/frame/browser_view.cc
@@ -2313,7 +2313,7 @@ void BrowserView::ToolbarSizeChanged(boo
 }
 
 void BrowserView::TabDraggingStatusChanged(bool is_dragging) {
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   std::vector<ContentsWebView*> contents_web_views =
       GetAllVisibleContentsWebViews();
 
@@ -5880,7 +5880,7 @@ void BrowserView::MaybeShowProfileSwitch
 }
 
 void BrowserView::MaybeShowSupervisedUserProfileSignInIPH() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!ShouldShowAvatarToolbarIPH()) {
     return;
   }
@@ -5890,7 +5890,7 @@ void BrowserView::MaybeShowSupervisedUse
 }
 
 void BrowserView::MaybeShowSignInBenefitsIPH() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!ShouldShowAvatarToolbarIPH()) {
     return;
   }
