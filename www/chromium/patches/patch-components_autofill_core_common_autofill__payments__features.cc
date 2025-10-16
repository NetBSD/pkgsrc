$NetBSD: patch-components_autofill_core_common_autofill__payments__features.cc,v 1.8 2025/10/16 19:43:25 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/autofill/core/common/autofill_payments_features.cc.orig	2025-10-13 21:41:26.000000000 +0000
+++ components/autofill/core/common/autofill_payments_features.cc
@@ -25,7 +25,7 @@ BASE_FEATURE(kAutofillEnableAllowlistFor
 BASE_FEATURE(kAutofillEnableAmountExtraction,
              "AutofillEnableAmountExtraction",
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT);
 #else
              base::FEATURE_DISABLED_BY_DEFAULT);
@@ -51,7 +51,7 @@ BASE_FEATURE(kAutofillEnableAmountExtrac
 BASE_FEATURE(kAutofillEnableBuyNowPayLater,
              "AutofillEnableBuyNowPayLater",
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT);
 #else
              base::FEATURE_DISABLED_BY_DEFAULT);
@@ -74,7 +74,7 @@ BASE_FEATURE(kAutofillEnableBuyNowPayLat
 BASE_FEATURE(kAutofillEnableBuyNowPayLaterSyncing,
              "AutofillEnableBuyNowPayLaterSyncing",
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT);
 #else
              base::FEATURE_DISABLED_BY_DEFAULT);
@@ -337,7 +337,7 @@ BASE_FEATURE(kDisableAutofillStrikeSyste
              base::FEATURE_DISABLED_BY_DEFAULT);
 
 bool ShouldShowImprovedUserConsentForCreditCardSave() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // The new user consent UI is fully launched on MacOS, Windows and Linux.
   return true;
 #else
