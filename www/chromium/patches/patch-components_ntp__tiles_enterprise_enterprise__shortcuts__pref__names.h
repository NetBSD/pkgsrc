$NetBSD: patch-components_ntp__tiles_enterprise_enterprise__shortcuts__pref__names.h,v 1.1 2026/11/08 15:39:00 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/ntp_tiles/enterprise/enterprise_shortcuts_pref_names.h.orig	2026-11-02 23:22:33.000000000 +0000
+++ components/ntp_tiles/enterprise/enterprise_shortcuts_pref_names.h
@@ -16,7 +16,7 @@ namespace ntp_tiles::prefs {
 
 // Prefs used to cache enterprise shortcuts.
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 inline constexpr char kEnterpriseShortcutsPolicyList[] =
     "enterprise_shortcuts.policy_list";
 inline constexpr char kEnterpriseShortcutsUserList[] =
