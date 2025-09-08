$NetBSD: patch-components_autofill_core_browser_payments_bnpl__manager.cc,v 1.5 2025/09/08 13:24:22 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/autofill/core/browser/payments/bnpl_manager.cc.orig	2025-08-29 18:50:09.000000000 +0000
+++ components/autofill/core/browser/payments/bnpl_manager.cc
@@ -497,7 +497,7 @@ void BnplManager::MaybeUpdateSuggestions
       .OnBnplSuggestionShown();
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   payments_autofill_client().GetPaymentsDataManager().SetAutofillHasSeenBnpl();
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_CHROMEOS)
