$NetBSD: patch-chrome_browser_gcm_gcm__profile__service__factory.cc,v 1.33 2026/11/19 19:45:53 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/gcm/gcm_profile_service_factory.cc.orig	2026-11-11 21:01:38.000000000 +0000
+++ chrome/browser/gcm/gcm_profile_service_factory.cc
@@ -108,7 +108,7 @@ GCMProfileServiceFactory::ScopedTestingF
 // static
 GCMProfileService* GCMProfileServiceFactory::GetForProfile(
     content::BrowserContext* profile) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // On desktop, incognito profiles are checked with IsIncognitoProfile().
   // It's possible for non-incognito profiles to also be off-the-record.
   bool is_profile_supported =
@@ -149,7 +149,7 @@ std::unique_ptr<KeyedService>
 GCMProfileServiceFactory::BuildServiceInstanceForBrowserContext(
     content::BrowserContext* context) const {
   Profile* profile = Profile::FromBrowserContext(context);
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   CHECK(!profile->IsIncognitoProfile(), base::NotFatalUntil::M161);
 #else
   CHECK(!profile->IsOffTheRecord(), base::NotFatalUntil::M161);
