$NetBSD: patch-components_autofill_core_browser_suggestions_payments_payments__suggestion__generator__util.cc,v 1.7 2026/11/19 19:45:58 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/autofill/core/browser/suggestions/payments/payments_suggestion_generator_util.cc.orig	2026-11-11 21:01:38.000000000 +0000
+++ components/autofill/core/browser/suggestions/payments/payments_suggestion_generator_util.cc
@@ -1350,7 +1350,7 @@ Suggestion CreateCreditCardSuggestion(
   }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Newly-synced cards start with a `use_count()` of 1.
   if (credit_card.card_creation_source() ==
           CreditCard::CardCreationSource::kCreationSourceNonChromePayments &&
