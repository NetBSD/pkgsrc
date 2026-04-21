$NetBSD: patch-chrome_browser_enterprise_connectors_connectors__service.cc,v 1.18 2026/04/21 15:21:09 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/enterprise/connectors/connectors_service.cc.orig	2026-04-14 23:31:37.000000000 +0200
+++ chrome/browser/enterprise/connectors/connectors_service.cc
@@ -308,7 +308,7 @@ policy::PolicyScope ConnectorsService::G
 bool ConnectorsService::ConnectorsEnabled() const {
   Profile* profile = Profile::FromBrowserContext(context_);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // On desktop, the guest profile is actually the primary OTR profile of
   // the "regular" guest profile.  The regular guest profile is never used
   // directly by users.  Also, user are not able to create child OTR profiles
