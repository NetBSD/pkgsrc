$NetBSD: patch-components_autofill_core_browser_suggestions_payments_payments__suggestion__generator__util.cc,v 1.1 2026/02/15 09:04:02 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/autofill/core/browser/suggestions/payments/payments_suggestion_generator_util.cc.orig	2026-02-03 22:07:10.000000000 +0000
+++ components/autofill/core/browser/suggestions/payments/payments_suggestion_generator_util.cc
@@ -959,7 +959,7 @@ std::vector<Suggestion> GetCreditCardSug
                              /*extracted_amount_in_micros=*/std::nullopt));
     manager.GetCreditCardFormEventLogger().OnBnplSuggestionShown();
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
     manager.client()
         .GetPersonalDataManager()
         .payments_data_manager()
