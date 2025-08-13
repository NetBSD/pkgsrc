$NetBSD: patch-components_autofill_core_common_autofill__prefs.h,v 1.5 2025/08/13 07:44:22 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/autofill/core/common/autofill_prefs.h.orig	2025-07-29 22:51:44.000000000 +0000
+++ components/autofill/core/common/autofill_prefs.h
@@ -32,7 +32,7 @@ inline constexpr std::string_view kAutof
 inline constexpr char kAutofillAiOptInStatus[] =
     "autofill.autofill_ai.opt_in_status";
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Boolean that is true if BNPL on Autofill is enabled.
 inline constexpr char kAutofillBnplEnabled[] = "autofill.bnpl_enabled";
 // Boolean that is true if the user has ever seen a BNPL suggestion.
@@ -226,7 +226,7 @@ void SetFacilitatedPaymentsPixAccountLin
 bool IsFacilitatedPaymentsPixAccountLinkingEnabled(const PrefService* prefs);
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 void SetAutofillBnplEnabled(PrefService* prefs, bool value);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_CHROMEOS)
@@ -234,7 +234,7 @@ void SetAutofillBnplEnabled(PrefService*
 bool IsAutofillBnplEnabled(const PrefService* prefs);
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 void SetAutofillHasSeenBnpl(PrefService* prefs);
 
 bool HasSeenBnpl(const PrefService* prefs);
