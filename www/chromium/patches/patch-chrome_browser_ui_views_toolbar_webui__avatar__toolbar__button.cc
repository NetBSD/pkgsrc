$NetBSD: patch-chrome_browser_ui_views_toolbar_webui__avatar__toolbar__button.cc,v 1.9 2026/10/13 13:16:35 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/toolbar/webui_avatar_toolbar_button.cc.orig	2026-10-06 00:06:58.000000000 +0000
+++ chrome/browser/ui/views/toolbar/webui_avatar_toolbar_button.cc
@@ -223,7 +223,7 @@ void WebUIAvatarToolbarButton::MaybeShow
   }
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void WebUIAvatarToolbarButton::MaybeShowSupervisedUserSignInIPH() {
   if (state_manager_ && delegate_->GetView()->GetWidget()) {
     state_manager_->MaybeShowSupervisedUserSignInIPH();
