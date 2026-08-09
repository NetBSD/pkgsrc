$NetBSD: patch-chrome_browser_safe__browsing_chrome__password__protection__service.cc,v 1.24 2026/08/09 06:31:09 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/safe_browsing/chrome_password_protection_service.cc.orig	2026-08-05 20:17:42.000000000 +0000
+++ chrome/browser/safe_browsing/chrome_password_protection_service.cc
@@ -1383,7 +1383,7 @@ std::string ChromePasswordProtectionServ
     ReusedPasswordAccountType password_type) const {
   if (base::FeatureList::IsEnabled(
           safe_browsing::kEnterprisePasswordReuseUiRefresh)) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     return GetPrefs()->GetString(prefs::kEnterpriseCustomLabelForProfile);
 #else
     return std::string();
