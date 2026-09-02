$NetBSD: patch-components_autofill_core_browser_payments_bnpl__manager.cc,v 1.24 2026/09/02 13:13:28 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/autofill/core/browser/payments/bnpl_manager.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ components/autofill/core/browser/payments/bnpl_manager.cc
@@ -1113,7 +1113,7 @@ void BnplManager::MaybeUpdateDesktopSugg
       .OnBnplSuggestionShown();
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   payments_autofill_client().GetPaymentsDataManager().SetAutofillHasSeenBnpl();
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_CHROMEOS)
