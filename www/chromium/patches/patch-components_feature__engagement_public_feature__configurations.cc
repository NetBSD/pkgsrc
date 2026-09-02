$NetBSD: patch-components_feature__engagement_public_feature__configurations.cc,v 1.25 2026/09/02 13:13:28 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/feature_engagement/public/feature_configurations.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ components/feature_engagement/public/feature_configurations.cc
@@ -102,7 +102,7 @@ std::optional<FeatureConfig> CreateNewUs
 std::optional<FeatureConfig> GetClientSideFeatureConfig(
     const base::Feature* feature) {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (kIPHPasswordsManagementBubbleAfterSaveFeature.name == feature->name) {
     FeatureConfig config;
     config.valid = true;
@@ -2397,7 +2397,7 @@ std::optional<FeatureConfig> GetClientSi
 #endif  // BUILDFLAG(IS_ANDROID)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 
   if (kIPHAutofillCreditCardBenefitFeature.name == feature->name) {
     // The credit card benefit IPH appears up to three times over 10 years and
