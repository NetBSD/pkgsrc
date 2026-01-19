$NetBSD: patch-components_autofill_core_browser_data__manager_payments_payments__data__manager.h,v 1.14 2026/01/19 16:14:12 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/autofill/core/browser/data_manager/payments/payments_data_manager.h.orig	2026-01-07 00:50:30.000000000 +0000
+++ components/autofill/core/browser/data_manager/payments/payments_data_manager.h
@@ -379,7 +379,7 @@ class PaymentsDataManager : public Autof
 
   // TODO(crbug.com/430575808): Remove build flags.
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   // Returns the value of the kAutofillHasSeenBnpl pref.
   virtual bool IsAutofillHasSeenBnplPrefEnabled() const;
 
@@ -727,7 +727,7 @@ class PaymentsDataManager : public Autof
   void ClearAllCreditCardBenefits();
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   // Monitors the `kAutofillBnplEnabled` preference for changes and controls the
   // clearing/loading of payment instruments accordingly. Will also log the
   // `Autofill.SettingsPage.BnplToggled` metric.
