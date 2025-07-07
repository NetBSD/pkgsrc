$NetBSD: patch-components_autofill_core_browser_data__manager_payments_payments__data__manager.cc,v 1.2 2025/07/07 09:23:29 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/autofill/core/browser/data_manager/payments/payments_data_manager.cc.orig	2025-06-30 06:54:11.000000000 +0000
+++ components/autofill/core/browser/data_manager/payments/payments_data_manager.cc
@@ -472,7 +472,7 @@ void PaymentsDataManager::OnWebDataServi
 
 bool PaymentsDataManager::ShouldShowBnplSettings() const {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Check `kAutofillEnableBuyNowPayLater` only if the user has seen a BNPL
   // suggestion before, or there are already linked issuers present, to avoid
   // unnecessary feature flag checks. The linked issuer check is due to the fact
@@ -983,7 +983,7 @@ void PaymentsDataManager::SetPrefService
           &PaymentsDataManager::OnAutofillPaymentsCardBenefitsPrefChange,
           base::Unretained(this)));
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   pref_registrar_.Add(
       prefs::kAutofillBnplEnabled,
       base::BindRepeating(&PaymentsDataManager::OnBnplEnabledPrefChange,
@@ -1067,7 +1067,7 @@ void PaymentsDataManager::SetAutofillHas
 }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 bool PaymentsDataManager::IsAutofillHasSeenBnplPrefEnabled() const {
   return prefs::HasSeenBnpl(pref_service_);
 }
@@ -2060,7 +2060,7 @@ bool PaymentsDataManager::AreEwalletAcco
 
 bool PaymentsDataManager::AreBnplIssuersSupported() const {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return app_locale_ == "en-US" && GetCountryCodeForExperimentGroup() == "US" &&
          base::FeatureList::IsEnabled(
              features::kAutofillEnableBuyNowPayLaterSyncing);
@@ -2093,7 +2093,7 @@ void PaymentsDataManager::ClearAllCredit
 }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 void PaymentsDataManager::OnBnplEnabledPrefChange() {
   // On pref change to `false`, clearing BNPL issuers is implicitly handled by
   // `GetBnplIssuers()`, since it returns an empty vector when
