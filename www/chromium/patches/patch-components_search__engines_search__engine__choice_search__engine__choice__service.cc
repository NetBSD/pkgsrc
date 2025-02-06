$NetBSD: patch-components_search__engines_search__engine__choice_search__engine__choice__service.cc,v 1.1 2025/02/06 09:58:02 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/search_engines/search_engine_choice/search_engine_choice_service.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ components/search_engines/search_engine_choice/search_engine_choice_service.cc
@@ -613,7 +613,7 @@ void SearchEngineChoiceService::Register
 
 int SearchEngineChoiceService::GetCountryIdInternal() {
   // `country_codes::kCountryIDAtInstall` may not be set yet.
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // On Android, ChromeOS and Linux, `country_codes::kCountryIDAtInstall` is
   // computed asynchronously using platform-specific signals, and may not be
   // available yet.
