$NetBSD: patch-chrome_browser_first__run_first__run.cc,v 1.9 2026/08/09 06:31:08 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/first_run/first_run.cc.orig	2026-08-05 20:17:42.000000000 +0000
+++ chrome/browser/first_run/first_run.cc
@@ -309,7 +309,7 @@ void SetupInitialPrefsFromInstallPrefs(
     out_prefs->confirm_to_quit = true;
 #endif  // BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   install_prefs.GetBool(installer::initial_preferences::kRequireEula,
                         &out_prefs->eula_required);
 #endif  // BUILDFLAG(IS_LINUX)
@@ -458,7 +458,7 @@ ProcessInitialPreferencesResult ProcessI
   return FIRST_RUN_PROCEED;
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool ShowEulaDialog() {
   return internal::ShowEulaDialog();
 }
