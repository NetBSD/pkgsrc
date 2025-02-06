$NetBSD: patch-chrome_browser_supervised__user_supervised__user__browser__utils.cc,v 1.1 2025/02/06 09:57:51 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/supervised_user/supervised_user_browser_utils.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ chrome/browser/supervised_user/supervised_user_browser_utils.cc
@@ -40,7 +40,7 @@
 #include "chrome/browser/ash/profiles/profile_helper.h"
 #include "components/user_manager/user.h"
 #include "components/user_manager/user_type.h"
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/supervised_user/supervised_user_verification_controller_client.h"
 #include "chrome/browser/supervised_user/supervised_user_verification_page_blocked_sites.h"
 #include "chrome/browser/supervised_user/supervised_user_verification_page_youtube.h"
@@ -158,7 +158,7 @@ void AssertChildStatusOfTheUser(Profile*
 #endif
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 std::string CreateReauthenticationInterstitialForYouTube(
     content::NavigationHandle& navigation_handle) {
   content::WebContents* web_contents = navigation_handle.GetWebContents();
