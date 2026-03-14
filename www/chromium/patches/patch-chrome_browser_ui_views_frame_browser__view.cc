$NetBSD: patch-chrome_browser_ui_views_frame_browser__view.cc,v 1.16 2026/03/14 12:40:28 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/frame/browser_view.cc.orig	2026-03-11 22:12:25.000000000 +0000
+++ chrome/browser/ui/views/frame/browser_view.cc
@@ -2437,7 +2437,7 @@ void BrowserView::ToolbarSizeChanged(boo
 }
 
 void BrowserView::TabDraggingStatusChanged(bool is_dragging) {
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   UpdateFastResizeForContentViews(is_dragging);
 
   if (!is_dragging) {
@@ -5924,7 +5924,7 @@ void BrowserView::MaybeShowProfileSwitch
 }
 
 void BrowserView::MaybeShowSupervisedUserProfileSignInIPH() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!ShouldShowAvatarToolbarIPH()) {
     return;
   }
@@ -5934,7 +5934,7 @@ void BrowserView::MaybeShowSupervisedUse
 }
 
 void BrowserView::MaybeShowSignInBenefitsIPH() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!ShouldShowAvatarToolbarIPH()) {
     return;
   }
