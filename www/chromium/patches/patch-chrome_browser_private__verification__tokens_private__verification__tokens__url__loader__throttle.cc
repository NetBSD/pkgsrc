$NetBSD: patch-chrome_browser_private__verification__tokens_private__verification__tokens__url__loader__throttle.cc,v 1.3 2026/10/13 13:16:33 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/private_verification_tokens/private_verification_tokens_url_loader_throttle.cc.orig	2026-10-06 00:06:58.000000000 +0000
+++ chrome/browser/private_verification_tokens/private_verification_tokens_url_loader_throttle.cc
@@ -54,6 +54,10 @@ void PrivateVerificationTokensURLLoaderT
     return;
   }
 
+#if BUILDFLAG(IS_BSD)
+  LOG(ERROR) << __FUNCTION__ << "crubit not implemented.";
+  return;
+#else
   // Token header should not already exist, remove it if it does.
   request->headers.RemoveHeader(
       net::HttpRequestHeaders::kSecPrivateVerificationToken);
@@ -88,6 +92,7 @@ void PrivateVerificationTokensURLLoaderT
           token_info->second);
     }
   }
+#endif
 }
 
 void PrivateVerificationTokensURLLoaderThrottle::WillRedirectRequest(
@@ -95,6 +100,10 @@ void PrivateVerificationTokensURLLoaderT
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
@@ -109,12 +118,17 @@ void PrivateVerificationTokensURLLoaderT
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
@@ -126,4 +140,5 @@ void PrivateVerificationTokensURLLoaderT
     token_id_.reset();
     redeemer_origin_.reset();
   }
+#endif
 }
