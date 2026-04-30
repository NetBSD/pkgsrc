$NetBSD: patch-src_3rdparty_chromium_components_autofill_core_common_autofill__payments__features.cc,v 1.2 2026/04/30 06:39:37 adam Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/components/autofill/core/common/autofill_payments_features.cc.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/components/autofill/core/common/autofill_payments_features.cc
@@ -355,7 +355,7 @@ BASE_FEATURE(kDisableAutofillStrikeSyste
              base::FEATURE_DISABLED_BY_DEFAULT);
 
 bool ShouldShowImprovedUserConsentForCreditCardSave() {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // The new user consent UI is fully launched on MacOS, Windows and Linux.
   return true;
 #else
