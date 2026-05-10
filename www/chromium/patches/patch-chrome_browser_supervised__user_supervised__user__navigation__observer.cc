$NetBSD: patch-chrome_browser_supervised__user_supervised__user__navigation__observer.cc,v 1.19 2026/05/10 15:29:51 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/supervised_user/supervised_user_navigation_observer.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ chrome/browser/supervised_user/supervised_user_navigation_observer.cc
@@ -55,7 +55,7 @@
 #include "components/supervised_user/core/browser/android/android_parental_controls.h"
 #elif BUILDFLAG(IS_CHROMEOS)
 #include "chrome/browser/supervised_user/chromeos/supervised_user_web_content_handler_impl.h"
-#elif BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#elif BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/supervised_user/linux_mac_windows/supervised_user_web_content_handler_impl.h"
 #endif
 
@@ -75,7 +75,7 @@ std::unique_ptr<supervised_user::WebCont
 #elif BUILDFLAG(IS_ANDROID)
   return std::make_unique<SupervisedUserWebContentHandlerImpl>(
       web_contents, frame_id, navigation_id);
-#elif BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#elif BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   return std::make_unique<SupervisedUserWebContentHandlerImpl>(
       web_contents, frame_id, navigation_id);
 #endif
