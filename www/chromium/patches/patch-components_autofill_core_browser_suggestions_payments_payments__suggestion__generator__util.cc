$NetBSD: patch-components_autofill_core_browser_suggestions_payments_payments__suggestion__generator__util.cc,v 1.4 2026/10/16 15:30:50 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/autofill/core/browser/suggestions/payments/payments_suggestion_generator_util.cc.orig	2026-10-14 21:09:54.000000000 +0000
+++ components/autofill/core/browser/suggestions/payments/payments_suggestion_generator_util.cc
@@ -1347,7 +1347,7 @@ Suggestion CreateCreditCardSuggestion(
   }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Newly-synced cards start with a `use_count()` of 1.
   if (credit_card.card_creation_source() ==
           CreditCard::CardCreationSource::kCreationSourceNonChromePayments &&
