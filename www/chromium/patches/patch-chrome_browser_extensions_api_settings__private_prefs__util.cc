$NetBSD: patch-chrome_browser_extensions_api_settings__private_prefs__util.cc,v 1.19 2026/05/10 15:29:49 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/extensions/api/settings_private/prefs_util.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ chrome/browser/extensions/api/settings_private/prefs_util.cc
@@ -223,7 +223,7 @@ const PrefsUtil::TypedPrefMap& PrefsUtil
   (*s_allowlist)[autofill::prefs::kAutofillPaymentCardBenefits] =
       settings_api::PrefType::kBoolean;
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   (*s_allowlist)[autofill::prefs::kAutofillBnplEnabled] =
       settings_api::PrefType::kBoolean;
   (*s_allowlist)[autofill::prefs::kAutofillAiIdentityEntitiesEnabled] =
@@ -257,7 +257,7 @@ const PrefsUtil::TypedPrefMap& PrefsUtil
   (*s_allowlist)[tab_groups::prefs::kAutoPinNewTabGroups] =
       settings_api::PrefType::kBoolean;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   (*s_allowlist)[::prefs::kUseCustomChromeFrame] =
       settings_api::PrefType::kBoolean;
 #endif
@@ -276,7 +276,7 @@ const PrefsUtil::TypedPrefMap& PrefsUtil
   (*s_allowlist)[::prefs::kPinnedActions] = settings_api::PrefType::kList;
   (*s_allowlist)[themes::prefs::kPolicyThemeColor] =
       settings_api::PrefType::kNumber;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   (*s_allowlist)[::prefs::kSystemTheme] = settings_api::PrefType::kNumber;
 #endif
   (*s_allowlist)[::prefs::kHomePage] = settings_api::PrefType::kUrl;
