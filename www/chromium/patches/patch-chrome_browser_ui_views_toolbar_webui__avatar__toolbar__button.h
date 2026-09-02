$NetBSD: patch-chrome_browser_ui_views_toolbar_webui__avatar__toolbar__button.h,v 1.5 2026/09/02 13:13:26 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/toolbar/webui_avatar_toolbar_button.h.orig	2026-08-31 22:47:51.000000000 +0000
+++ chrome/browser/ui/views/toolbar/webui_avatar_toolbar_button.h
@@ -57,7 +57,7 @@ class WebUIAvatarToolbarButton : public 
       bool should_announce) override;
   bool HasExplicitButtonState() const override;
   void MaybeShowProfileSwitchIPH() override;
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void MaybeShowSupervisedUserSignInIPH() override;
   void MaybeShowSignInBenefitsIPH() override;
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
