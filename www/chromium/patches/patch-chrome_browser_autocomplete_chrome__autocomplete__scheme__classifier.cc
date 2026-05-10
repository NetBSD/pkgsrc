$NetBSD: patch-chrome_browser_autocomplete_chrome__autocomplete__scheme__classifier.cc,v 1.19 2026/05/10 15:29:48 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/autocomplete/chrome_autocomplete_scheme_classifier.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ chrome/browser/autocomplete/chrome_autocomplete_scheme_classifier.cc
@@ -103,7 +103,7 @@ ChromeAutocompleteSchemeClassifier::GetI
       return metrics::OmniboxInputType::QUERY;
 
     case ExternalProtocolHandler::UNKNOWN: {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       // Linux impl of GetApplicationNameForScheme doesn't distinguish
       // between URL schemes with handers and those without. This will
       // make the default behaviour be search on Linux.
