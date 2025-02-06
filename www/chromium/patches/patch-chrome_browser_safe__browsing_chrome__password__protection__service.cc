$NetBSD: patch-chrome_browser_safe__browsing_chrome__password__protection__service.cc,v 1.1 2025/02/06 09:57:50 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/safe_browsing/chrome_password_protection_service.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ chrome/browser/safe_browsing/chrome_password_protection_service.cc
@@ -1250,7 +1250,7 @@ std::string ChromePasswordProtectionServ
     ReusedPasswordAccountType password_type) const {
   if (base::FeatureList::IsEnabled(
           safe_browsing::kEnterprisePasswordReuseUiRefresh)) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     return GetPrefs()->GetString(prefs::kEnterpriseCustomLabel);
 #else
     return std::string();
