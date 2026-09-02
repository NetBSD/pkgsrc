$NetBSD: patch-chrome_browser_extensions_api_settings__private_prefs__util.cc,v 1.25 2026/09/02 13:13:23 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/extensions/api/settings_private/prefs_util.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ chrome/browser/extensions/api/settings_private/prefs_util.cc
@@ -242,7 +242,7 @@ const PrefsUtil::TypedPrefMap& PrefsUtil
   (*s_allowlist)[autofill::prefs::kAutofillPaymentCardBenefits] =
       settings_api::PrefType::kBoolean;
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   (*s_allowlist)[autofill::prefs::kAutofillBnplEnabled] =
       settings_api::PrefType::kBoolean;
   (*s_allowlist)[autofill::prefs::kAutofillAtMemoryTriggerInfo] =
@@ -294,7 +294,7 @@ const PrefsUtil::TypedPrefMap& PrefsUtil
   (*s_allowlist)[tab_groups::prefs::kAutoPinNewTabGroups] =
       settings_api::PrefType::kBoolean;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   (*s_allowlist)[::prefs::kUseCustomChromeFrame] =
       settings_api::PrefType::kBoolean;
 #endif
@@ -316,7 +316,7 @@ const PrefsUtil::TypedPrefMap& PrefsUtil
   (*s_allowlist)[::prefs::kPinnedActions] = settings_api::PrefType::kList;
   (*s_allowlist)[themes::prefs::kPolicyThemeColor] =
       settings_api::PrefType::kNumber;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   (*s_allowlist)[::prefs::kSystemTheme] = settings_api::PrefType::kNumber;
 #endif
   (*s_allowlist)[::prefs::kHomePage] = settings_api::PrefType::kUrl;
