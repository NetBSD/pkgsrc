$NetBSD: patch-chrome_browser_prefs_pref__service__incognito__allowlist.cc,v 1.10 2025/11/20 08:36:08 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/prefs/pref_service_incognito_allowlist.cc.orig	2025-11-14 20:31:45.000000000 +0000
+++ chrome/browser/prefs/pref_service_incognito_allowlist.cc
@@ -203,7 +203,7 @@ const char* const kPersistentPrefNames[]
     prefs::kShowFullscreenToolbar,
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // Toggleing custom frames affects all open windows in the profile, hence
     // should be written to the regular profile when changed in incognito mode.
     prefs::kUseCustomChromeFrame,
