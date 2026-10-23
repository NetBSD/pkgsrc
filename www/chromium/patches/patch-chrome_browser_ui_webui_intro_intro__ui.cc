$NetBSD: patch-chrome_browser_ui_webui_intro_intro__ui.cc,v 1.5 2026/10/23 15:05:22 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/webui/intro/intro_ui.cc.orig	2026-10-19 20:07:21.000000000 +0000
+++ chrome/browser/ui/webui/intro/intro_ui.cc
@@ -55,7 +55,7 @@ int GetBackupCardDescriptionId(bool is_f
              : IDS_UNO_FRE_BACKUP_CARD_DESCRIPTION_WITH_PASSWORDS;
 }
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 bool IsDefaultBrowserDisabledByPolicy() {
   const auto* local_state = g_browser_process->local_state();
   return local_state->IsManagedPreference(
@@ -65,7 +65,7 @@ bool IsDefaultBrowserDisabledByPolicy() 
 #endif  // BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
 bool ShouldShowDefaultBrowserToggle() {
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return !IsDefaultBrowserDisabledByPolicy() &&
          shell_integration::CanSetAsDefaultBrowser();
 #else
@@ -75,7 +75,7 @@ bool ShouldShowDefaultBrowserToggle() {
 
 bool ShouldShowMetricsOptIn() {
 #if BUILDFLAG(GOOGLE_CHROME_BRANDING) && \
-    (BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX))
+    (BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
   return !metrics::IsMetricsReportingPolicyManaged();
 #else
   return false;
