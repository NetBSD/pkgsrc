$NetBSD: patch-components_autofill_core_browser_integrators_optimization__guide_autofill__optimization__guide__decider.cc,v 1.11 2026/04/21 15:21:13 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/autofill/core/browser/integrators/optimization_guide/autofill_optimization_guide_decider.cc.orig	2026-04-14 23:31:37.000000000 +0200
+++ components/autofill/core/browser/integrators/optimization_guide/autofill_optimization_guide_decider.cc
@@ -207,7 +207,7 @@ void AddOptimizationTypesForBnplIssuers(
     base::flat_set<optimization_guide::proto::OptimizationType>&
         optimization_types) {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   auto bnpl_issuer_allowlist_can_be_loaded =
       [&bnpl_issuers](BnplIssuer::IssuerId issuer_id) {
         return std::ranges::contains(bnpl_issuers, issuer_id,
