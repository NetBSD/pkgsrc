$NetBSD: patch-chrome_browser_private__verification__tokens_private__verification__tokens__url__loader__throttle.cc,v 1.1 2026/09/29 07:42:50 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/private_verification_tokens/private_verification_tokens_url_loader_throttle.cc.orig	2026-09-22 00:09:16.000000000 +0000
+++ chrome/browser/private_verification_tokens/private_verification_tokens_url_loader_throttle.cc
@@ -52,7 +52,10 @@ void PrivateVerificationTokensURLLoaderT
       !pvt_service_) {
     return;
   }
-
+#if BUILDFLAG(IS_BSD)
+  LOG(ERROR) << __FUNCTION__ << "crubit not implemented.";
+  return;
+#else
   // Token header should not already exist, remove it if it does.
   request->headers.RemoveHeader(
       net::HttpRequestHeaders::kSecPrivateVerificationToken);
@@ -83,6 +86,7 @@ void PrivateVerificationTokensURLLoaderT
           token_info->second);
     }
   }
+#endif
 }
 
 void PrivateVerificationTokensURLLoaderThrottle::WillRedirectRequest(
@@ -96,7 +100,7 @@ void PrivateVerificationTokensURLLoaderT
   }
   if (token_id_.has_value()) {
     if (pvt_service_ && !response_head.pvt_token_removed_due_to_cookies) {
-      pvt_service_->DeleteToken(*token_id_, base::DoNothing());
+//      pvt_service_->DeleteToken(*token_id_, base::DoNothing());
     }
     token_id_.reset();
   }
@@ -109,7 +113,7 @@ void PrivateVerificationTokensURLLoaderT
   if (token_id_.has_value()) {
     if (pvt_service_ && response_head &&
         !response_head->pvt_token_removed_due_to_cookies) {
-      pvt_service_->DeleteToken(*token_id_, base::DoNothing());
+//      pvt_service_->DeleteToken(*token_id_, base::DoNothing());
     }
     token_id_.reset();
   }
