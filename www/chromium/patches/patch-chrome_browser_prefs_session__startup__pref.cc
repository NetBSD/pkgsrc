$NetBSD: patch-chrome_browser_prefs_session__startup__pref.cc,v 1.4 2025/12/13 14:53:50 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/prefs/session_startup_pref.cc.orig	2025-11-19 21:40:05.000000000 +0000
+++ chrome/browser/prefs/session_startup_pref.cc
@@ -71,7 +71,7 @@ SessionStartupPref::Type SessionStartupP
 #if BUILDFLAG(IS_CHROMEOS)
   return SessionStartupPref::LAST;
 #else
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   if (features::kSetDefaultToContinueSession.Get()) {
     return SessionStartupPref::LAST;
   }
