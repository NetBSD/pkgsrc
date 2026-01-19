$NetBSD: patch-components_error__page_common_localized__error.cc,v 1.13 2026/01/19 16:14:13 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/error_page/common/localized_error.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ components/error_page/common/localized_error.cc
@@ -889,7 +889,7 @@ void AddSuggestionsDetails(int error_cod
   if (suggestions & SUGGEST_PROXY_CONFIG) {
     // Custom body string.
     std::u16string inner =
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
         l10n_util::GetStringFUTF16(
             IDS_ERRORPAGES_SUGGESTION_PROXY_DISABLE_PLATFORM,
             l10n_util::GetStringUTF16(IDS_SETTINGS_TITLE),
