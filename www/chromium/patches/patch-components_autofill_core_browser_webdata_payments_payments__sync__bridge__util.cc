$NetBSD: patch-components_autofill_core_browser_webdata_payments_payments__sync__bridge__util.cc,v 1.3 2025/08/13 07:44:22 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/autofill/core/browser/webdata/payments/payments_sync_bridge_util.cc.orig	2025-07-29 22:51:44.000000000 +0000
+++ components/autofill/core/browser/webdata/payments/payments_sync_bridge_util.cc
@@ -1262,7 +1262,7 @@ bool AreMaskedBankAccountSupported() {
 
 bool IsBnplIssuerSupported() {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return base::FeatureList::IsEnabled(
       features::kAutofillEnableBuyNowPayLaterSyncing);
 #else
