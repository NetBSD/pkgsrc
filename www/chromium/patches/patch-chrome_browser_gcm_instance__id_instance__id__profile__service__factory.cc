$NetBSD: patch-chrome_browser_gcm_instance__id_instance__id__profile__service__factory.cc,v 1.1 2025/02/06 09:57:48 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/gcm/instance_id/instance_id_profile_service_factory.cc.orig	2024-12-17 17:58:49.000000000 +0000
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
@@ -64,7 +64,7 @@ InstanceIDProfileServiceFactory::~Instan
 KeyedService* InstanceIDProfileServiceFactory::BuildServiceInstanceFor(
     content::BrowserContext* context) const {
   Profile* profile = Profile::FromBrowserContext(context);
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // On desktop, incognito profiles are checked with IsIncognitoProfile().
   // It's possible for non-incognito profiles to also be off-the-record.
   bool is_incognito = profile->IsIncognitoProfile();
