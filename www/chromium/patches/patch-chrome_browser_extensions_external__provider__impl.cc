$NetBSD: patch-chrome_browser_extensions_external__provider__impl.cc,v 1.1 2025/02/06 09:57:48 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/extensions/external_provider_impl.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ chrome/browser/extensions/external_provider_impl.cc
@@ -792,7 +792,7 @@ void ExternalProviderImpl::CreateExterna
 
 #endif  // BUILDFLAG(IS_CHROMEOS)
   if (!profile->GetPrefs()->GetBoolean(pref_names::kBlockExternalExtensions)) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     provider_list->push_back(std::make_unique<ExternalProviderImpl>(
         service,
         base::MakeRefCounted<ExternalPrefLoader>(
@@ -820,7 +820,7 @@ void ExternalProviderImpl::CreateExterna
         bundled_extension_creation_flags));
 
     // Define a per-user source of external extensions.
-#if BUILDFLAG(IS_MAC) || ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && \
+#if BUILDFLAG(IS_MAC) || ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)) && \
                           BUILDFLAG(CHROMIUM_BRANDING))
     provider_list->push_back(std::make_unique<ExternalProviderImpl>(
         service,
