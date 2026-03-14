$NetBSD: patch-chrome_browser_first__run_first__run.cc,v 1.1 2026/03/14 12:40:26 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/first_run/first_run.cc.orig	2026-03-11 22:12:25.000000000 +0000
+++ chrome/browser/first_run/first_run.cc
@@ -319,7 +319,7 @@ void SetupInitialPrefsFromInstallPrefs(
     out_prefs->confirm_to_quit = true;
 #endif  // BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   install_prefs.GetBool(installer::initial_preferences::kRequireEula,
                         &out_prefs->eula_required);
 #endif  // BUILDFLAG(IS_LINUX)
@@ -468,7 +468,7 @@ ProcessInitialPreferencesResult ProcessI
   return FIRST_RUN_PROCEED;
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool ShowEulaDialog() {
   return internal::ShowEulaDialog();
 }
