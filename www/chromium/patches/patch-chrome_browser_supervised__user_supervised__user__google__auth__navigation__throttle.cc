$NetBSD: patch-chrome_browser_supervised__user_supervised__user__google__auth__navigation__throttle.cc,v 1.1 2025/02/06 09:57:51 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/supervised_user/supervised_user_google_auth_navigation_throttle.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ chrome/browser/supervised_user/supervised_user_google_auth_navigation_throttle.cc
@@ -32,7 +32,7 @@
 #include "chrome/browser/supervised_user/child_accounts/child_account_service_android.h"
 #include "components/signin/public/identity_manager/identity_manager.h"
 #include "ui/android/view_android.h"
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/supervised_user/supervised_user_verification_controller_client.h"
 #include "chrome/browser/supervised_user/supervised_user_verification_page.h"
 #endif
@@ -148,7 +148,7 @@ SupervisedUserGoogleAuthNavigationThrott
     return content::NavigationThrottle::DEFER;
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   // When an unauthenticated supervised user tries to access YouTube, we force
   // re-authentication with an interstitial so that YouTube can be subject to
   // content restrictions. This interstitial is only available on Desktop
