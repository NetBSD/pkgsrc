$NetBSD: patch-components_autofill_core_browser_suggestions_payments_payments__suggestion__generator.cc,v 1.3 2025/12/23 13:22:16 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/autofill/core/browser/suggestions/payments/payments_suggestion_generator.cc.orig	2025-12-17 23:05:18.000000000 +0000
+++ components/autofill/core/browser/suggestions/payments/payments_suggestion_generator.cc
@@ -1462,7 +1462,7 @@ std::vector<Suggestion> GetCreditCardSug
                                  .GetBnplIssuers(),
                              /*extracted_amount_in_micros=*/std::nullopt));
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
     manager.client()
         .GetPersonalDataManager()
         .payments_data_manager()
