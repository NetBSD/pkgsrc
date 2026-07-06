$NetBSD: patch-chrome_browser_ui_views_profiles_avatar__toolbar__button.h,v 1.21 2026/07/06 13:06:46 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/profiles/avatar_toolbar_button.h.orig	2026-06-23 23:37:18.000000000 +0000
+++ chrome/browser/ui/views/profiles/avatar_toolbar_button.h
@@ -70,7 +70,7 @@ class AvatarToolbarButton : public Toolb
   void SetAnnounceCallbackForTesting(
       base::OnceCallback<void(std::u16string)> callback) override;
   void MaybeShowProfileSwitchIPH() override;
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void MaybeShowSupervisedUserSignInIPH() override;
   void MaybeShowSignInBenefitsIPH() override;
 #endif
