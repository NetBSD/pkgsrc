$NetBSD: patch-components_autofill_core_browser_data__manager_payments_payments__data__manager.h,v 1.5 2025/09/08 13:24:22 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/autofill/core/browser/data_manager/payments/payments_data_manager.h.orig	2025-08-29 18:50:09.000000000 +0000
+++ components/autofill/core/browser/data_manager/payments/payments_data_manager.h
@@ -370,7 +370,7 @@ class PaymentsDataManager : public Autof
   void SetAutofillHasSeenIban();
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Returns the value of the kAutofillHasSeenBnpl pref.
   bool IsAutofillHasSeenBnplPrefEnabled() const;
 
@@ -699,7 +699,7 @@ class PaymentsDataManager : public Autof
   void ClearAllCreditCardBenefits();
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Monitors the `kAutofillBnplEnabled` preference for changes and controls the
   // clearing/loading of payment instruments accordingly. Will also log the
   // `Autofill.SettingsPage.BnplToggled` metric.
