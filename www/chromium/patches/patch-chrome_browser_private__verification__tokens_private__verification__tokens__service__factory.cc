$NetBSD: patch-chrome_browser_private__verification__tokens_private__verification__tokens__service__factory.cc,v 1.2 2026/10/02 11:43:23 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/private_verification_tokens/private_verification_tokens_service_factory.cc.orig	2026-09-22 00:09:16.000000000 +0000
+++ chrome/browser/private_verification_tokens/private_verification_tokens_service_factory.cc
@@ -102,6 +102,10 @@ PrivateVerificationTokensServiceFactory:
           net::features::kEnablePrivateVerificationTokens)) {
     return nullptr;
   }
+#if BUILDFLAG(IS_BSD)
+  LOG(ERROR) << __FUNCTION__ << "crubit not implemented.";
+  return nullptr;
+#else
   Profile* profile = Profile::FromBrowserContext(context);
   CHECK(profile);
   auto service = PrivateVerificationTokensService::Create(
@@ -113,6 +117,7 @@ PrivateVerificationTokensServiceFactory:
     }
   }
   return service;
+#endif
 }
 
 bool PrivateVerificationTokensServiceFactory::
