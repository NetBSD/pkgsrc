$NetBSD: patch-components_ntp__tiles_most__visited__sites.cc,v 1.2 2026/11/19 19:45:59 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/ntp_tiles/most_visited_sites.cc.orig	2026-11-11 21:01:38.000000000 +0000
+++ components/ntp_tiles/most_visited_sites.cc
@@ -52,7 +52,7 @@
 #endif
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "components/ntp_tiles/enterprise/enterprise_shortcuts_pref_names.h"
 #include "components/ntp_tiles/enterprise/enterprise_shortcuts_store.h"
 #endif
@@ -1012,7 +1012,7 @@ bool MostVisitedSites::IsNtpTileFromPrei
 // static
 bool MostVisitedSites::HasEnterpriseShortcuts(const PrefService& prefs) {
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return EnterpriseShortcutsStore::HasPolicyLinks(prefs);
 #else
   return false;
@@ -1024,7 +1024,7 @@ void MostVisitedSites::AddEnterpriseShor
     PrefChangeRegistrar& registrar,
     const base::RepeatingClosure& callback) {
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   registrar.Add(prefs::kEnterpriseShortcutsPolicyList, callback);
 #endif
 }
