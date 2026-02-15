$NetBSD: patch-components_error__page_common_localized__error.cc,v 1.14 2026/02/15 09:04:02 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/error_page/common/localized_error.cc.orig	2026-02-03 22:07:10.000000000 +0000
+++ components/error_page/common/localized_error.cc
@@ -898,7 +898,7 @@ void AddSuggestionsDetails(int error_cod
   if (suggestions & SUGGEST_PROXY_CONFIG) {
     // Custom body string.
     std::u16string inner =
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
         l10n_util::GetStringFUTF16(
             IDS_ERRORPAGES_SUGGESTION_PROXY_DISABLE_PLATFORM,
             l10n_util::GetStringUTF16(IDS_SETTINGS_TITLE),
