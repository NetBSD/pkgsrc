$NetBSD: patch-chrome_browser_signin_signin__hats__util.cc,v 1.21 2026/09/02 13:13:24 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/signin/signin_hats_util.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ chrome/browser/signin/signin_hats_util.cc
@@ -45,7 +45,7 @@
 
 namespace {
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 constexpr char kChannel[] = "Channel";
 constexpr char kChromeVersion[] = "Chrome Version";
 constexpr char kNumberOfChromeProfiles[] = "Number of Chrome Profiles";
@@ -231,7 +231,7 @@ void LaunchHatsSurveyForProfileInternal(
     Profile* profile,
     bool defer_if_no_browser,
     base::OnceCallback<SurveyStringData()> data_factory) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!profile || !IsSurveyEnabledForHatsTrigger(trigger)) {
     return;
   }
@@ -277,7 +277,7 @@ void LaunchHatsSurveyForProfile(const st
                                     access_point_for_data_type_promo) {
   LaunchHatsSurveyForProfileInternal(
       trigger, profile, defer_if_no_browser,
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       base::BindOnce(&GetSurveyStringData, trigger, profile,
                      access_point_for_data_type_promo)
 #else
