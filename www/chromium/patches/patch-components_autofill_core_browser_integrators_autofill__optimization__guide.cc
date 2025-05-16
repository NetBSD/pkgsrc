$NetBSD: patch-components_autofill_core_browser_integrators_autofill__optimization__guide.cc,v 1.1 2025/05/16 16:08:21 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/autofill/core/browser/integrators/autofill_optimization_guide.cc.orig	2025-05-05 19:21:24.000000000 +0000
+++ components/autofill/core/browser/integrators/autofill_optimization_guide.cc
@@ -231,7 +231,7 @@ void AutofillOptimizationGuide::OnDidPar
   }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   auto bnpl_issuer_allowlist_can_be_loaded =
       [&payments_data_manager](std::string_view issuer_id) {
         return base::Contains(payments_data_manager.GetBnplIssuers(), issuer_id,
