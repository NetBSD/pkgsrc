$NetBSD: patch-chrome_browser_enterprise_connectors_common.cc,v 1.6 2025/09/08 13:24:18 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/enterprise/connectors/common.cc.orig	2025-08-29 18:50:09.000000000 +0000
+++ chrome/browser/enterprise/connectors/common.cc
@@ -19,7 +19,7 @@
 #include "components/user_manager/user.h"
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/signin/enterprise_signin_prefs.h"
 #include "components/prefs/pref_service.h"
 #endif
@@ -235,7 +235,7 @@ std::string GetProfileEmail(Profile* pro
   std::string email =
       GetProfileEmail(IdentityManagerFactory::GetForProfile(profile));
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (email.empty()) {
     email = profile->GetPrefs()->GetString(
         enterprise_signin::prefs::kProfileUserEmail);
