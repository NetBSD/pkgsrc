$NetBSD: patch-src_3rdparty_chromium_chrome_browser_signin_signin__hats__util.cc,v 1.1 2026/04/30 06:39:36 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/chrome/browser/signin/signin_hats_util.cc.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/chrome/browser/signin/signin_hats_util.cc
@@ -36,7 +36,7 @@
 
 namespace {
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 constexpr char kChannel[] = "Channel";
 constexpr char kChromeVersion[] = "Chrome Version";
 constexpr char kNumberOfChromeProfiles[] = "Number of Chrome Profiles";
@@ -153,7 +153,7 @@ SurveyStringData GetSigninSurveyStringDa
 namespace signin {
 
 bool IsFeatureEnabledForSigninHatsTrigger(const std::string& trigger) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   for (const auto& entry : kChromeIdentityHatsTriggerFeatureMapping) {
     if (trigger == entry.trigger) {
       return base::FeatureList::IsEnabled(*entry.feature);
@@ -171,7 +171,7 @@ void LaunchSigninHatsSurveyForProfile(co
                                       bool defer_if_no_browser,
                                       std::optional<signin_metrics::AccessPoint>
                                           access_point_for_data_type_promo) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!profile || !IsFeatureEnabledForSigninHatsTrigger(trigger)) {
     return;
   }
