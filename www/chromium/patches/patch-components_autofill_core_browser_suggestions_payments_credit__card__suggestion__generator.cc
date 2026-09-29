$NetBSD: patch-components_autofill_core_browser_suggestions_payments_credit__card__suggestion__generator.cc,v 1.9 2026/09/29 07:42:53 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/autofill/core/browser/suggestions/payments/credit_card_suggestion_generator.cc.orig	2026-09-22 00:09:16.000000000 +0000
+++ components/autofill/core/browser/suggestions/payments/credit_card_suggestion_generator.cc
@@ -176,7 +176,7 @@ using SuggestionDataSource = SuggestionG
 
 bool IsSaveAndFillEnabled() {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return base::FeatureList::IsEnabled(features::kAutofillEnableSaveAndFill);
 #elif BUILDFLAG(IS_IOS)
   return base::FeatureList::IsEnabled(
