$NetBSD: patch-components_autofill_core_browser_payments_bnpl__manager.cc,v 1.32 2026/11/19 19:45:58 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/autofill/core/browser/payments/bnpl_manager.cc.orig	2026-11-11 21:01:38.000000000 +0000
+++ components/autofill/core/browser/payments/bnpl_manager.cc
@@ -1177,7 +1177,7 @@ void BnplManager::MaybeUpdateDesktopSugg
           /*pay_later_tab_shown=*/false);
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   payments_autofill_client().GetPaymentsDataManager().SetAutofillHasSeenBnpl();
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_CHROMEOS)
