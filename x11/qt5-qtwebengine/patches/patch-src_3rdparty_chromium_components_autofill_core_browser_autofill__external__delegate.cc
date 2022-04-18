$NetBSD: patch-src_3rdparty_chromium_components_autofill_core_browser_autofill__external__delegate.cc,v 1.2 2022/04/18 11:18:18 adam Exp $

--- src/3rdparty/chromium/components/autofill/core/browser/autofill_external_delegate.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/components/autofill/core/browser/autofill_external_delegate.cc
@@ -128,7 +128,7 @@ void AutofillExternalDelegate::OnSuggest
     // Append the "Hide Suggestions" menu item for only Autofill Address and
     // Autocomplete popups.
 #if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_APPLE) || \
-    defined(OS_CHROMEOS)
+    defined(OS_CHROMEOS) || defined(OS_BSD)
   if (base::FeatureList::IsEnabled(
           features::kAutofillEnableHideSuggestionsUI)) {
     // If the user has selected a suggestion, it indicates the suggestions are
