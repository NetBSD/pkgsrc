$NetBSD: patch-components_autofill_core_browser_autofill__optimization__guide.cc,v 1.1 2025/02/06 09:57:58 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/autofill/core/browser/autofill_optimization_guide.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ components/autofill/core/browser/autofill_optimization_guide.cc
@@ -186,7 +186,7 @@ void AutofillOptimizationGuide::OnDidPar
     }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     if (has_credit_card_field &&
         !personal_data_manager->payments_data_manager()
              .GetServerCreditCards()
