$NetBSD: patch-chrome_browser_autocomplete_chrome__autocomplete__scheme__classifier.cc,v 1.1 2025/02/06 09:57:45 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/autocomplete/chrome_autocomplete_scheme_classifier.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ chrome/browser/autocomplete/chrome_autocomplete_scheme_classifier.cc
@@ -88,7 +88,7 @@ ChromeAutocompleteSchemeClassifier::GetI
       return metrics::OmniboxInputType::QUERY;
 
     case ExternalProtocolHandler::UNKNOWN: {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
       // Linux impl of GetApplicationNameForScheme doesn't distinguish
       // between URL schemes with handers and those without. This will
       // make the default behaviour be search on Linux.
