$NetBSD: patch-chrome_browser_gcm_instance__id_instance__id__profile__service__factory.cc,v 1.14 2026/01/19 16:14:09 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/gcm/instance_id/instance_id_profile_service_factory.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ chrome/browser/gcm/instance_id/instance_id_profile_service_factory.cc
@@ -16,7 +16,7 @@ namespace instance_id {
 // static
 InstanceIDProfileService* InstanceIDProfileServiceFactory::GetForProfile(
     content::BrowserContext* profile) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // On desktop, the guest profile is actually the primary OTR profile of
   // the "regular" guest profile.  The regular guest profile is never used
   // directly by users.  Also, user are not able to create child OTR profiles
@@ -65,7 +65,7 @@ std::unique_ptr<KeyedService>
 InstanceIDProfileServiceFactory::BuildServiceInstanceForBrowserContext(
     content::BrowserContext* context) const {
   Profile* profile = Profile::FromBrowserContext(context);
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // On desktop, incognito profiles are checked with IsIncognitoProfile().
   // It's possible for non-incognito profiles to also be off-the-record.
   bool is_incognito = profile->IsIncognitoProfile();
