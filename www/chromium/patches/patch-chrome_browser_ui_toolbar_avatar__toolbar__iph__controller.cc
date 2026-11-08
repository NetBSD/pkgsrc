$NetBSD: patch-chrome_browser_ui_toolbar_avatar__toolbar__iph__controller.cc,v 1.1 2026/11/08 15:38:56 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/toolbar/avatar_toolbar_iph_controller.cc.orig	2026-11-02 23:22:33.000000000 +0000
+++ chrome/browser/ui/toolbar/avatar_toolbar_iph_controller.cc
@@ -123,7 +123,7 @@ void AvatarToolbarIphController::MaybeSh
 }
 
 void AvatarToolbarIphController::MaybeShowSupervisedUserProfileSignInIPHImpl() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!ShouldShowAvatarToolbarIPH()) {
     return;
   }
@@ -174,7 +174,7 @@ void AvatarToolbarIphController::MaybeSh
 }
 
 void AvatarToolbarIphController::MaybeShowSignInBenefitsIPHImpl() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!ShouldShowAvatarToolbarIPH()) {
     return;
   }
