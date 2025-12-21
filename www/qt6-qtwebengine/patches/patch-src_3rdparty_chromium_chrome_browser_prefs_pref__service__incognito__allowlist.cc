$NetBSD: patch-src_3rdparty_chromium_chrome_browser_prefs_pref__service__incognito__allowlist.cc,v 1.1 2025/12/21 09:38:19 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/chrome/browser/prefs/pref_service_incognito_allowlist.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/chrome/browser/prefs/pref_service_incognito_allowlist.cc
@@ -199,7 +199,7 @@ const char* const kPersistentPrefNames[]
     prefs::kShowFullscreenToolbar,
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // Toggleing custom frames affects all open windows in the profile, hence
     // should be written to the regular profile when changed in incognito mode.
     prefs::kUseCustomChromeFrame,
