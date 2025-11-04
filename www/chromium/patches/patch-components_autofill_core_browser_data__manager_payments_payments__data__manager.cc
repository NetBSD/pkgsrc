$NetBSD: patch-components_autofill_core_browser_data__manager_payments_payments__data__manager.cc,v 1.8 2025/11/04 14:55:37 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/autofill/core/browser/data_manager/payments/payments_data_manager.cc.orig	2025-10-24 16:42:30.000000000 +0000
+++ components/autofill/core/browser/data_manager/payments/payments_data_manager.cc
@@ -479,7 +479,7 @@ void PaymentsDataManager::OnWebDataServi
 
 bool PaymentsDataManager::ShouldShowBnplSettings() const {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   // Check `kAutofillEnableBuyNowPayLater` only if the user has seen a BNPL
   // suggestion before, or there are already linked issuers present, to avoid
   // unnecessary feature flag checks. The linked issuer check is due to the fact
@@ -1014,7 +1014,7 @@ void PaymentsDataManager::SetPrefService
           &PaymentsDataManager::OnAutofillPaymentsCardBenefitsPrefChange,
           base::Unretained(this)));
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   pref_registrar_.Add(
       prefs::kAutofillBnplEnabled,
       base::BindRepeating(&PaymentsDataManager::OnBnplEnabledPrefChange,
@@ -1088,7 +1088,7 @@ void PaymentsDataManager::SetAutofillHas
 }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 bool PaymentsDataManager::IsAutofillHasSeenBnplPrefEnabled() const {
   return prefs::HasSeenBnpl(pref_service_);
 }
@@ -2125,7 +2125,7 @@ bool PaymentsDataManager::AreEwalletAcco
 
 bool PaymentsDataManager::AreBnplIssuersSupported() const {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   return (app_locale_ == "en-US" || app_locale_ == "en-GB" ||
           app_locale_ == "en-CA") &&
          GetCountryCodeForExperimentGroup() == "US" &&
@@ -2160,7 +2160,7 @@ void PaymentsDataManager::ClearAllCredit
 }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 void PaymentsDataManager::OnBnplEnabledPrefChange() {
   // On pref change to `false`, clearing BNPL issuers is implicitly handled by
   // `GetBnplIssuers()`, since it returns an empty vector when
