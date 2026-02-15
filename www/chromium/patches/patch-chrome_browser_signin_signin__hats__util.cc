$NetBSD: patch-chrome_browser_signin_signin__hats__util.cc,v 1.11 2026/02/15 09:03:59 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/signin/signin_hats_util.cc.orig	2026-02-03 22:07:10.000000000 +0000
+++ chrome/browser/signin/signin_hats_util.cc
@@ -39,7 +39,7 @@
 
 namespace {
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 constexpr char kChannel[] = "Channel";
 constexpr char kChromeVersion[] = "Chrome Version";
 constexpr char kNumberOfChromeProfiles[] = "Number of Chrome Profiles";
@@ -123,7 +123,7 @@ SurveyStringData GetSigninSurveyStringDa
 namespace signin {
 
 bool IsFeatureEnabledForSigninHatsTrigger(const std::string& trigger) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   static const base::NoDestructor<
       base::flat_map<std::string_view, const base::Feature*>>
       kChromeIdentityHatsTriggerFeatureMap({
@@ -168,7 +168,7 @@ void LaunchSigninHatsSurveyForProfile(co
                                       bool defer_if_no_browser,
                                       std::optional<signin_metrics::AccessPoint>
                                           access_point_for_data_type_promo) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!profile || !IsFeatureEnabledForSigninHatsTrigger(trigger)) {
     return;
   }
