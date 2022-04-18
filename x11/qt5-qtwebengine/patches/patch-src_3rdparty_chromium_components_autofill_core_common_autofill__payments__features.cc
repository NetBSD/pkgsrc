$NetBSD: patch-src_3rdparty_chromium_components_autofill_core_common_autofill__payments__features.cc,v 1.2 2022/04/18 11:18:18 adam Exp $

--- src/3rdparty/chromium/components/autofill/core/common/autofill_payments_features.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/components/autofill/core/common/autofill_payments_features.cc
@@ -122,7 +122,7 @@ const base::Feature kAutofillUpstreamAll
     "AutofillUpstreamAllowAllEmailDomains", base::FEATURE_DISABLED_BY_DEFAULT};
 
 bool ShouldShowImprovedUserConsentForCreditCardSave() {
-#if defined(OS_WIN) || defined(OS_APPLE) || \
+#if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_BSD) || \
     (defined(OS_LINUX) && !defined(OS_CHROMEOS))
   // The new user consent UI is fully launched on MacOS, Windows and Linux.
   return true;
