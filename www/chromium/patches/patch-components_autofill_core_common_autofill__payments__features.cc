$NetBSD: patch-components_autofill_core_common_autofill__payments__features.cc,v 1.24 2026/08/09 06:31:14 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/autofill/core/common/autofill_payments_features.cc.orig	2026-08-05 20:17:42.000000000 +0000
+++ components/autofill/core/common/autofill_payments_features.cc
@@ -32,7 +32,7 @@ BASE_FEATURE(kAutofillDisableBnplCountry
 // page using server-side AI.
 BASE_FEATURE(kAutofillEnableAiBasedAmountExtraction,
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT);
 #else
              base::FEATURE_DISABLED_BY_DEFAULT);
@@ -48,7 +48,7 @@ BASE_FEATURE(kAutofillEnableAiCardRecomm
 // of the allowlisted merchant websites.
 BASE_FEATURE(kAutofillEnableAmountExtraction,
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT);
 #else
              base::FEATURE_DISABLED_BY_DEFAULT);
@@ -81,7 +81,7 @@ BASE_FEATURE(kAutofillEnableBottomSheetS
 // When enabled, buy now pay later (BNPL) in Autofill will be offered.
 BASE_FEATURE(kAutofillEnableBuyNowPayLater,
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT);
 #else
              base::FEATURE_DISABLED_BY_DEFAULT);
@@ -92,7 +92,7 @@ BASE_FEATURE(kAutofillEnableBuyNowPayLat
 // (BNPL) issuers that are externally linked.
 BASE_FEATURE(kAutofillEnableBuyNowPayLaterForExternallyLinked,
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT);
 #else
              base::FEATURE_DISABLED_BY_DEFAULT);
@@ -103,7 +103,7 @@ BASE_FEATURE(kAutofillEnableBuyNowPayLat
 // offered.
 BASE_FEATURE(kAutofillEnableBuyNowPayLaterForKlarna,
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT);
 #else
              base::FEATURE_DISABLED_BY_DEFAULT);
@@ -113,7 +113,7 @@ BASE_FEATURE(kAutofillEnableBuyNowPayLat
 // When enabled, buy now pay later (BNPL) data will be synced to Chrome clients.
 BASE_FEATURE(kAutofillEnableBuyNowPayLaterSyncing,
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT);
 #else
              base::FEATURE_DISABLED_BY_DEFAULT);
@@ -124,7 +124,7 @@ BASE_FEATURE(kAutofillEnableBuyNowPayLat
 // include the issuer names for better brand recognition.
 BASE_FEATURE(kAutofillEnableBuyNowPayLaterUpdatedSuggestionSecondLineString,
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT);
 #else
              base::FEATURE_DISABLED_BY_DEFAULT);
@@ -144,7 +144,7 @@ BASE_FEATURE(kAutofillEnableCardBenefits
 // UI.
 BASE_FEATURE(kAutofillEnableCardBenefitsForBmo,
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT);
 #else
              base::FEATURE_DISABLED_BY_DEFAULT);
@@ -183,7 +183,7 @@ BASE_FEATURE(kAutofillEnableFlatRateCard
 // Payments Autofill UI.
 BASE_FEATURE(kAutofillEnableFlatRateCardBenefitsFromCurinos,
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT);
 #else
              base::FEATURE_DISABLED_BY_DEFAULT);
@@ -271,7 +271,7 @@ BASE_FEATURE(kAutofillEnableTravelCatego
 // the card, and FIDO is not.
 BASE_FEATURE(kAutofillEnableVcn3dsAuthentication,
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT);
 #else
              base::FEATURE_DISABLED_BY_DEFAULT);
@@ -300,7 +300,7 @@ BASE_FEATURE(kAutofillEnableWalletBrandi
 // eligibility.
 BASE_FEATURE(kAutofillPreferBuyNowPayLaterBlocklists,
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT);
 #else
              base::FEATURE_DISABLED_BY_DEFAULT);
@@ -346,7 +346,7 @@ BASE_FEATURE(kAutofillUpstreamEnforceStr
              base::FEATURE_DISABLED_BY_DEFAULT);
 
 bool ShouldShowImprovedUserConsentForCreditCardSave() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // The new user consent UI is fully launched on MacOS, Windows and Linux.
   return true;
 #else
