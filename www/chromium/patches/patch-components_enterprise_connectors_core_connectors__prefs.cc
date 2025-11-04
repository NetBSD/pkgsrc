$NetBSD: patch-components_enterprise_connectors_core_connectors__prefs.cc,v 1.1 2025/11/04 14:55:37 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/enterprise/connectors/core/connectors_prefs.cc.orig	2025-10-24 16:42:30.000000000 +0000
+++ components/enterprise/connectors/core/connectors_prefs.cc
@@ -22,7 +22,7 @@
 namespace enterprise_connectors {
 
 // Profile Prefs
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const char kCacheEncryptionEnabledPref[] =
     "enterprise_connectors.cache_encryption_enabled";
 #endif
@@ -96,7 +96,7 @@ void RegisterProfilePrefs(PrefRegistrySi
 #if BUILDFLAG(ENTERPRISE_CLIENT_CERTIFICATES)
   client_certificates::RegisterProfilePrefs(registry);
 #endif  // BUILDFLAG(ENTERPRISE_CLIENT_CERTIFICATES)
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   registry->RegisterBooleanPref(kCacheEncryptionEnabledPref, false);
 #endif
 }
