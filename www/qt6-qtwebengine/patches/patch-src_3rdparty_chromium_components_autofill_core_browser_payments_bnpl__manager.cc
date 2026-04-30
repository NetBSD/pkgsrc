$NetBSD: patch-src_3rdparty_chromium_components_autofill_core_browser_payments_bnpl__manager.cc,v 1.1 2026/04/30 06:39:37 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/components/autofill/core/browser/payments/bnpl_manager.cc.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/components/autofill/core/browser/payments/bnpl_manager.cc
@@ -497,7 +497,7 @@ void BnplManager::MaybeUpdateSuggestions
       .OnBnplSuggestionShown();
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   payments_autofill_client().GetPaymentsDataManager().SetAutofillHasSeenBnpl();
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_CHROMEOS)
