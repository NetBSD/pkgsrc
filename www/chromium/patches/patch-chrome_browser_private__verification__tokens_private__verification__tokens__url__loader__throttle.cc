$NetBSD: patch-chrome_browser_private__verification__tokens_private__verification__tokens__url__loader__throttle.cc,v 1.5 2026/10/23 15:05:19 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/private_verification_tokens/private_verification_tokens_url_loader_throttle.cc.orig	2026-10-19 20:07:21.000000000 +0000
+++ chrome/browser/private_verification_tokens/private_verification_tokens_url_loader_throttle.cc
@@ -57,6 +57,10 @@ void PrivateVerificationTokensURLLoaderT
     return;
   }
 
+#if BUILDFLAG(IS_BSD)
+  LOG(ERROR) << __FUNCTION__ << "crubit not implemented.";
+  return;
+#else
   // Token header should not already exist, remove it if it does.
   request->headers.RemoveHeader(
       net::HttpRequestHeaders::kSecPrivateVerificationToken);
@@ -110,6 +114,7 @@ void PrivateVerificationTokensURLLoaderT
           token_info->second);
     }
   }
+#endif
 }
 
 void PrivateVerificationTokensURLLoaderThrottle::WillRedirectRequest(
@@ -117,6 +122,10 @@ void PrivateVerificationTokensURLLoaderT
     const network::mojom::URLResponseHead& response_head,
     bool* defer,
     network::HttpRequestHeadersUpdateParams* headers_update_params) {
+#if BUILDFLAG(IS_BSD)
+  LOG(ERROR) << __FUNCTION__ << "crubit not implemented.";
+  return;
+#else
   if (headers_update_params) {
     headers_update_params->removed_headers.push_back(
         net::HttpRequestHeaders::kSecPrivateVerificationToken);
@@ -131,12 +140,17 @@ void PrivateVerificationTokensURLLoaderT
     token_id_.reset();
     redeemer_origin_.reset();
   }
+#endif
 }
 
 void PrivateVerificationTokensURLLoaderThrottle::WillProcessResponse(
     const GURL& response_url,
     network::mojom::URLResponseHead* response_head,
     bool* defer) {
+#if BUILDFLAG(IS_BSD)
+  LOG(ERROR) << __FUNCTION__ << "crubit not implemented.";
+  return;
+#else
   if (token_id_.has_value()) {
     if (pvt_service_ && response_head &&
         !response_head->pvt_token_removed_due_to_cookies) {
@@ -148,4 +162,5 @@ void PrivateVerificationTokensURLLoaderT
     token_id_.reset();
     redeemer_origin_.reset();
   }
+#endif
 }
