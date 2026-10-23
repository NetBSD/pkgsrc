$NetBSD: patch-chrome_browser_browsing__data_chrome__browsing__data__remover__delegate.cc,v 1.5 2026/10/23 15:05:16 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/browsing_data/chrome_browsing_data_remover_delegate.cc.orig	2026-10-19 20:07:21.000000000 +0000
+++ chrome/browser/browsing_data/chrome_browsing_data_remover_delegate.cc
@@ -731,6 +731,7 @@ void ChromeBrowsingDataRemoverDelegate::
   if (remove_mask & constants::DATA_TYPE_PRIVATE_VERIFICATION_TOKENS) {
     if (base::FeatureList::IsEnabled(
             net::features::kEnablePrivateVerificationTokens)) {
+#if !BUILDFLAG(IS_BSD)
       if (auto* pvt_service =
               PrivateVerificationTokensServiceFactory::GetForProfile(
                   profile_)) {
@@ -747,6 +748,9 @@ void ChromeBrowsingDataRemoverDelegate::
               filter_builder->BuildStorageKeyFilter(), std::move(done_closure));
         }
       }
+#else
+      LOG(ERROR) << __FUNCTION__ << "crubit not implemented.";
+#endif
     }
   }
 
