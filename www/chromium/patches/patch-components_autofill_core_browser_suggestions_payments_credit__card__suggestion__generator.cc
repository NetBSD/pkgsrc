$NetBSD: patch-components_autofill_core_browser_suggestions_payments_credit__card__suggestion__generator.cc,v 1.2 2026/06/01 10:09:11 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/autofill/core/browser/suggestions/payments/credit_card_suggestion_generator.cc.orig	2026-05-26 20:39:02.000000000 +0000
+++ components/autofill/core/browser/suggestions/payments/credit_card_suggestion_generator.cc
@@ -43,7 +43,7 @@ using SuggestionData = SuggestionGenerat
 
 bool IsSaveAndFillEnabled() {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return base::FeatureList::IsEnabled(features::kAutofillEnableSaveAndFill);
 #elif BUILDFLAG(IS_IOS)
   return base::FeatureList::IsEnabled(
