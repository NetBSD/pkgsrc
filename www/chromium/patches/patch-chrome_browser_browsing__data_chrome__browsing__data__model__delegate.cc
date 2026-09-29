$NetBSD: patch-chrome_browser_browsing__data_chrome__browsing__data__model__delegate.cc,v 1.1 2026/09/29 07:42:47 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/browsing_data/chrome_browsing_data_model_delegate.cc.orig	2026-09-22 00:09:16.000000000 +0000
+++ chrome/browser/browsing_data/chrome_browsing_data_model_delegate.cc
@@ -129,12 +129,16 @@ void ChromeBrowsingDataModelDelegate::Ge
 
   if (base::FeatureList::IsEnabled(
           net::features::kEnablePrivateVerificationTokens)) {
+#if !BUILDFLAG(IS_BSD)
     if (auto* pvt_service =
             PrivateVerificationTokensServiceFactory::GetForProfile(profile_)) {
       pvt_service->GetTokenIssuers(
           base::BindOnce(&PrivateVerificationTokenBrowsingDataToDelegateEntries)
               .Then(concurrent.CreateCallback()));
     }
+#else
+    LOG(ERROR) << __FUNCTION__ << "crubit not implemented.";
+#endif
   }
 
   // TODO(crbug.com/40205603): Implement data retrieval for remaining data
@@ -184,6 +188,7 @@ void ChromeBrowsingDataModelDelegate::Re
           net::features::kEnablePrivateVerificationTokens) &&
       storage_types.Has(static_cast<BrowsingDataModel::StorageType>(
           StorageType::kPrivateVerificationTokens))) {
+#if !BUILDFLAG(IS_BSD)
     if (const url::Origin* origin = std::get_if<url::Origin>(&data_key)) {
       if (auto* pvt_service =
               PrivateVerificationTokensServiceFactory::GetForProfile(
@@ -193,6 +198,9 @@ void ChromeBrowsingDataModelDelegate::Re
                                   std::vector<url::Origin>{*origin});
       }
     }
+#else
+    LOG(ERROR) << __FUNCTION__ << "crubit not implemented.";
+#endif
   }
 
   std::move(concurrent).Done(std::move(callback));
