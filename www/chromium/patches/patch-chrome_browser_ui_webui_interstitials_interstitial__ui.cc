$NetBSD: patch-chrome_browser_ui_webui_interstitials_interstitial__ui.cc,v 1.1 2025/02/06 09:57:55 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/webui/interstitials/interstitial_ui.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ chrome/browser/ui/webui/interstitials/interstitial_ui.cc
@@ -74,7 +74,7 @@
 #include "components/security_interstitials/content/captive_portal_blocking_page.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/supervised_user/supervised_user_verification_controller_client.h"
 #include "chrome/browser/supervised_user/supervised_user_verification_page_blocked_sites.h"
 #include "chrome/browser/supervised_user/supervised_user_verification_page_youtube.h"
@@ -396,7 +396,7 @@ std::unique_ptr<EnterpriseWarnPage> Crea
                                                        kRequestUrl));
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 std::unique_ptr<SupervisedUserVerificationPageForYouTube>
 CreateSupervisedUserVerificationPageForYouTube(
     content::WebContents* web_contents,
@@ -613,7 +613,7 @@ void InterstitialHTMLSource::StartDataRe
     interstitial_delegate = CreateInsecureFormPage(web_contents);
   } else if (path_without_query == "/https_only") {
     interstitial_delegate = CreateHttpsOnlyModePage(web_contents);
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   } else if (path_without_query == "/supervised-user-verify") {
     interstitial_delegate = CreateSupervisedUserVerificationPageForYouTube(
         web_contents, /*is_main_frame=*/true);
