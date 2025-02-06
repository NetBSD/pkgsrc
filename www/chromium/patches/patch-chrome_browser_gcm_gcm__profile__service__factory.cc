$NetBSD: patch-chrome_browser_gcm_gcm__profile__service__factory.cc,v 1.1 2025/02/06 09:57:48 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/gcm/gcm_profile_service_factory.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ chrome/browser/gcm/gcm_profile_service_factory.cc
@@ -89,7 +89,7 @@ GCMProfileServiceFactory::ScopedTestingF
 // static
 GCMProfileService* GCMProfileServiceFactory::GetForProfile(
     content::BrowserContext* profile) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // On desktop, incognito profiles are checked with IsIncognitoProfile().
   // It's possible for non-incognito profiles to also be off-the-record.
   bool is_profile_supported =
@@ -132,7 +132,7 @@ GCMProfileServiceFactory::~GCMProfileSer
 KeyedService* GCMProfileServiceFactory::BuildServiceInstanceFor(
     content::BrowserContext* context) const {
   Profile* profile = Profile::FromBrowserContext(context);
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   DCHECK(!profile->IsIncognitoProfile());
 #else
   DCHECK(!profile->IsOffTheRecord());
