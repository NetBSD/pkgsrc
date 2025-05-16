$NetBSD: patch-components_autofill_core_browser_payments_bnpl__manager.cc,v 1.1 2025/05/16 16:08:21 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/autofill/core/browser/payments/bnpl_manager.cc.orig	2025-05-05 19:21:24.000000000 +0000
+++ components/autofill/core/browser/payments/bnpl_manager.cc
@@ -114,7 +114,7 @@ void BnplManager::OnAmountExtractionRetu
 
 bool BnplManager::ShouldShowBnplSettings() const {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   const PaymentsDataManager& payments_data_manager =
       payments_autofill_client().GetPaymentsDataManager();
 
@@ -431,7 +431,7 @@ void BnplManager::MaybeUpdateSuggestions
       .Run(update_suggestions_result.suggestions, trigger_source);
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   payments_autofill_client().GetPaymentsDataManager().SetAutofillHasSeenBnpl();
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_CHROMEOS)
