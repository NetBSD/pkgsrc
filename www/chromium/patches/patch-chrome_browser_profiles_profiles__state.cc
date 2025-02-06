$NetBSD: patch-chrome_browser_profiles_profiles__state.cc,v 1.1 2025/02/06 09:57:50 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/profiles/profiles_state.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ chrome/browser/profiles/profiles_state.cc
@@ -190,7 +190,7 @@ bool IsGuestModeRequested(const base::Co
                           PrefService* local_state,
                           bool show_warning) {
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   DCHECK(local_state);
 
   // Check if guest mode enforcement commandline switch or policy are provided.
@@ -226,7 +226,7 @@ bool IsGuestModeEnabled() {
     return false;
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   // If there are any supervised profiles, disable guest mode.
   if (base::FeatureList::IsEnabled(
           supervised_user::kHideGuestModeForSupervisedUsers) &&
@@ -245,7 +245,7 @@ bool IsGuestModeEnabled() {
 }
 
 bool IsGuestModeEnabled(const Profile& profile) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(
           supervised_user::kHideGuestModeForSupervisedUsers)) {
     ProfileAttributesEntry* profile_attributes =
