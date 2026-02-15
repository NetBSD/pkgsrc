$NetBSD: patch-chrome_browser_prefs_session__startup__pref.cc,v 1.7 2026/02/15 09:03:59 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/prefs/session_startup_pref.cc.orig	2026-02-03 22:07:10.000000000 +0000
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
