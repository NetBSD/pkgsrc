$NetBSD: patch-components_enterprise_connectors_core_connectors__prefs.h,v 1.1 2025/11/04 14:55:37 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/enterprise/connectors/core/connectors_prefs.h.orig	2025-10-24 16:42:30.000000000 +0000
+++ components/enterprise/connectors/core/connectors_prefs.h
@@ -11,7 +11,7 @@ class PrefRegistrySimple;
 
 namespace enterprise_connectors {
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Pref that maps to the "CacheEncryptionEnabled" policy.
 extern const char kCacheEncryptionEnabledPref[];
 #endif
