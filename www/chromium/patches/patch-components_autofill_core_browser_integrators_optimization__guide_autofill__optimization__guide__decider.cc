$NetBSD: patch-components_autofill_core_browser_integrators_optimization__guide_autofill__optimization__guide__decider.cc,v 1.7 2026/01/19 16:14:12 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/autofill/core/browser/integrators/optimization_guide/autofill_optimization_guide_decider.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ components/autofill/core/browser/integrators/optimization_guide/autofill_optimization_guide_decider.cc
@@ -203,7 +203,7 @@ void AddOptimizationTypesForBnplIssuers(
     base::flat_set<optimization_guide::proto::OptimizationType>&
         optimization_types) {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   auto bnpl_issuer_allowlist_can_be_loaded =
       [&bnpl_issuers](BnplIssuer::IssuerId issuer_id) {
         return base::Contains(bnpl_issuers, issuer_id, &BnplIssuer::issuer_id);
