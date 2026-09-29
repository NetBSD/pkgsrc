$NetBSD: patch-chrome_browser_prefs_session__startup__pref.cc,v 1.19 2026/09/29 07:42:49 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/prefs/session_startup_pref.cc.orig	2026-09-22 00:09:16.000000000 +0000
+++ chrome/browser/prefs/session_startup_pref.cc
@@ -66,7 +66,7 @@ SessionStartupPref::Type SessionStartupP
 #if BUILDFLAG(IS_CHROMEOS)
   return SessionStartupPref::LAST;
 #else
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   if (features::kSetDefaultToContinueSession.Get()) {
     return SessionStartupPref::LAST;
   }
