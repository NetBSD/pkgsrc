$NetBSD: patch-components_autofill_core_browser_payments_bnpl__manager.cc,v 1.10 2025/12/11 09:13:35 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/autofill/core/browser/payments/bnpl_manager.cc.orig	2025-11-19 21:40:05.000000000 +0000
+++ components/autofill/core/browser/payments/bnpl_manager.cc
@@ -607,7 +607,7 @@ void BnplManager::MaybeUpdateDesktopSugg
       .OnBnplSuggestionShown();
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   payments_autofill_client().GetPaymentsDataManager().SetAutofillHasSeenBnpl();
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_CHROMEOS)
