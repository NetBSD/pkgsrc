$NetBSD: patch-components_autofill_core_common_autofill__prefs.cc,v 1.13 2025/12/23 13:22:16 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/autofill/core/common/autofill_prefs.cc.orig	2025-12-17 23:05:18.000000000 +0000
+++ components/autofill/core/common/autofill_prefs.cc
@@ -137,7 +137,7 @@ void RegisterProfilePrefs(user_prefs::Pr
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   registry->RegisterBooleanPref(
       kAutofillBnplEnabled, true,
       user_prefs::PrefRegistrySyncable::SYNCABLE_PREF);
@@ -386,7 +386,7 @@ void SetFacilitatedPaymentsA2ATriggeredO
 }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 void SetAutofillBnplEnabled(PrefService* prefs, bool value) {
   prefs->SetBoolean(kAutofillBnplEnabled, value);
 }
@@ -395,7 +395,7 @@ void SetAutofillBnplEnabled(PrefService*
 
 bool IsAutofillBnplEnabled(const PrefService* prefs) {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   return prefs->GetBoolean(kAutofillBnplEnabled);
 #else
   return false;
@@ -404,7 +404,7 @@ bool IsAutofillBnplEnabled(const PrefSer
 }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 // If called, always sets the pref to true, and once true, it will follow the
 // user around forever.
 void SetAutofillHasSeenBnpl(PrefService* prefs) {
