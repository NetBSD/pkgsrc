$NetBSD: patch-chrome_browser_signin_signin__hats__util.cc,v 1.13 2026/04/10 17:31:49 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/signin/signin_hats_util.cc.orig	2026-04-06 16:25:54.000000000 +0000
+++ chrome/browser/signin/signin_hats_util.cc
@@ -44,7 +44,7 @@
 
 namespace {
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 constexpr char kChannel[] = "Channel";
 constexpr char kChromeVersion[] = "Chrome Version";
 constexpr char kNumberOfChromeProfiles[] = "Number of Chrome Profiles";
@@ -217,7 +217,7 @@ void LaunchHatsSurveyForProfileInternal(
     Profile* profile,
     bool defer_if_no_browser,
     base::OnceCallback<SurveyStringData()> data_factory) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!profile || !IsSurveyEnabledForHatsTrigger(trigger)) {
     return;
   }
@@ -262,7 +262,7 @@ void LaunchHatsSurveyForProfile(const st
                                     access_point_for_data_type_promo) {
   LaunchHatsSurveyForProfileInternal(
       trigger, profile, defer_if_no_browser,
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       base::BindOnce(&GetSurveyStringData, trigger, profile,
                      access_point_for_data_type_promo)
 #else
