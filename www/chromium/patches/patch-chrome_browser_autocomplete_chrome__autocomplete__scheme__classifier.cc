$NetBSD: patch-chrome_browser_autocomplete_chrome__autocomplete__scheme__classifier.cc,v 1.26 2026/09/22 13:41:18 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/autocomplete/chrome_autocomplete_scheme_classifier.cc.orig	2026-09-14 22:17:16.000000000 +0000
+++ chrome/browser/autocomplete/chrome_autocomplete_scheme_classifier.cc
@@ -103,7 +103,7 @@ ChromeAutocompleteSchemeClassifier::GetI
       return metrics::OmniboxInputType::QUERY;
 
     case ExternalProtocolHandler::UNKNOWN: {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       // Linux impl of GetApplicationNameForScheme doesn't distinguish
       // between URL schemes with handers and those without. This will
       // make the default behaviour be search on Linux.
