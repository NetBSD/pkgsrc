$NetBSD: patch-components_autofill_core_common_autofill__prefs.h,v 1.1 2025/02/06 09:57:58 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/autofill/core/common/autofill_prefs.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ components/autofill/core/common/autofill_prefs.h
@@ -73,7 +73,7 @@ inline constexpr char kAutofillPaymentCv
 inline constexpr char kAutofillPaymentCardBenefits[] =
     "autofill.payment_card_benefits";
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Boolean that controls improved autofill filling predictions. When enabled,
 // the autofill functionality is enhanced with adopting user data to
 // the form being filled in, which is triggered by the user via an extra
