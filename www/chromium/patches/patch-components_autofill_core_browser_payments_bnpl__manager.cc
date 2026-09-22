$NetBSD: patch-components_autofill_core_browser_payments_bnpl__manager.cc,v 1.25 2026/09/22 13:41:23 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/autofill/core/browser/payments/bnpl_manager.cc.orig	2026-09-14 22:17:16.000000000 +0000
+++ components/autofill/core/browser/payments/bnpl_manager.cc
@@ -1177,7 +1177,7 @@ void BnplManager::MaybeUpdateDesktopSugg
           /*suggestion_contains_pay_later_tab_entry=*/false);
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   payments_autofill_client().GetPaymentsDataManager().SetAutofillHasSeenBnpl();
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_CHROMEOS)
