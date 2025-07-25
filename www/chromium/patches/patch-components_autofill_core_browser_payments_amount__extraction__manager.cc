$NetBSD: patch-components_autofill_core_browser_payments_amount__extraction__manager.cc,v 1.2 2025/07/25 16:17:14 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/autofill/core/browser/payments/amount_extraction_manager.cc.orig	2025-07-21 19:32:31.000000000 +0000
+++ components/autofill/core/browser/payments/amount_extraction_manager.cc
@@ -109,7 +109,7 @@ AmountExtractionManager::GetEligibleFeat
   }
 
   if constexpr (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
-                BUILDFLAG(IS_CHROMEOS)) {
+                BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) {
     if (base::FeatureList::IsEnabled(
             ::autofill::features::
                 kAutofillEnableAmountExtractionDesktopLogging)) {
@@ -188,7 +188,7 @@ void AmountExtractionManager::OnCheckout
     bnpl_manager->OnAmountExtractionReturned(parsed_extracted_amount);
   }
   if constexpr (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
-                BUILDFLAG(IS_CHROMEOS)) {
+                BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) {
     if (base::FeatureList::IsEnabled(
             ::autofill::features::
                 kAutofillEnableAmountExtractionDesktopLogging)) {
@@ -212,7 +212,7 @@ void AmountExtractionManager::OnTimeoutR
       autofill_metrics::AmountExtractionResult::kTimeout);
   // TODO(crbug.com/378517983): Add BNPL flow action logic here.
   if constexpr (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
-                BUILDFLAG(IS_CHROMEOS)) {
+                BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) {
     if (base::FeatureList::IsEnabled(
             ::autofill::features::
                 kAutofillEnableAmountExtractionDesktopLogging)) {
@@ -232,7 +232,7 @@ AmountExtractionManager::CheckEligiblili
   // Check eligibility of BNPL feature.
   // Currently, BNPL is only offered for desktop platforms.
   if constexpr (BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
-                BUILDFLAG(IS_CHROMEOS)) {
+                BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) {
     if (BnplManager* bnpl_manager = autofill_manager_->GetPaymentsBnplManager();
         bnpl_manager && bnpl_manager->IsEligibleForBnpl()) {
       eligible_features.insert(EligibleFeature::kBnpl);
