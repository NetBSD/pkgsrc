$NetBSD: patch-chrome_browser_ui_views_toolbar_webui__avatar__toolbar__button.cc,v 1.4 2026/08/09 06:31:12 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/toolbar/webui_avatar_toolbar_button.cc.orig	2026-08-05 20:17:42.000000000 +0000
+++ chrome/browser/ui/views/toolbar/webui_avatar_toolbar_button.cc
@@ -216,7 +216,7 @@ void WebUIAvatarToolbarButton::MaybeShow
   }
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void WebUIAvatarToolbarButton::MaybeShowSupervisedUserSignInIPH() {
   if (state_manager_ && delegate_->GetView()->GetWidget()) {
     state_manager_->MaybeShowSupervisedUserSignInIPH();
