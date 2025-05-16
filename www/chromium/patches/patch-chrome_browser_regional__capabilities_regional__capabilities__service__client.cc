$NetBSD: patch-chrome_browser_regional__capabilities_regional__capabilities__service__client.cc,v 1.1 2025/05/16 16:08:18 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/regional_capabilities/regional_capabilities_service_client.cc.orig	2025-05-05 19:21:24.000000000 +0000
+++ chrome/browser/regional_capabilities/regional_capabilities_service_client.cc
@@ -107,7 +107,7 @@ void RegionalCapabilitiesServiceClient::
       base::android::AttachCurrentThread(),
       reinterpret_cast<intptr_t>(heap_callback.release()));
 }
-#elif BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void RegionalCapabilitiesServiceClient::FetchCountryId(
     CountryIdCallback on_country_id_fetched) {
   std::move(on_country_id_fetched).Run(variations_latest_country_id_);
