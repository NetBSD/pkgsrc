$NetBSD: patch-components_autofill_core_common_autofill__prefs.cc,v 1.4 2025/07/25 16:17:14 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/autofill/core/common/autofill_prefs.cc.orig	2025-07-21 19:32:31.000000000 +0000
+++ components/autofill/core/common/autofill_prefs.cc
@@ -101,7 +101,7 @@ void RegisterProfilePrefs(user_prefs::Pr
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   registry->RegisterBooleanPref(
       kAutofillBnplEnabled, true,
       user_prefs::PrefRegistrySyncable::SYNCABLE_PREF);
@@ -280,7 +280,7 @@ bool IsFacilitatedPaymentsEwalletEnabled
 }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 void SetAutofillBnplEnabled(PrefService* prefs, bool value) {
   prefs->SetBoolean(kAutofillBnplEnabled, value);
 }
@@ -289,7 +289,7 @@ void SetAutofillBnplEnabled(PrefService*
 
 bool IsAutofillBnplEnabled(const PrefService* prefs) {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return prefs->GetBoolean(kAutofillBnplEnabled);
 #else
   return false;
@@ -298,7 +298,7 @@ bool IsAutofillBnplEnabled(const PrefSer
 }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // If called, always sets the pref to true, and once true, it will follow the
 // user around forever.
 void SetAutofillHasSeenBnpl(PrefService* prefs) {
