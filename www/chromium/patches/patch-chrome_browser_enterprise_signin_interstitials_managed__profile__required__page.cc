$NetBSD: patch-chrome_browser_enterprise_signin_interstitials_managed__profile__required__page.cc,v 1.4 2025/08/13 07:44:17 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/enterprise/signin/interstitials/managed_profile_required_page.cc.orig	2025-07-29 22:51:44.000000000 +0000
+++ chrome/browser/enterprise/signin/interstitials/managed_profile_required_page.cc
@@ -95,7 +95,7 @@ void ManagedProfileRequiredPage::Command
 
   switch (cmd) {
     case security_interstitials::CMD_DONT_PROCEED:
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       if (ManagedProfileRequiredNavigationThrottle::IsBlockingNavigations(
               web_contents()->GetBrowserContext())) {
         ManagedProfileRequiredNavigationThrottle::ShowBlockedWindow(
