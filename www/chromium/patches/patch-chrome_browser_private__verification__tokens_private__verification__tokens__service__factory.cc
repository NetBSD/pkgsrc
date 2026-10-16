$NetBSD: patch-chrome_browser_private__verification__tokens_private__verification__tokens__service__factory.cc,v 1.4 2026/10/16 15:30:46 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/private_verification_tokens/private_verification_tokens_service_factory.cc.orig	2026-10-14 21:09:54.000000000 +0000
+++ chrome/browser/private_verification_tokens/private_verification_tokens_service_factory.cc
@@ -108,6 +108,10 @@ PrivateVerificationTokensServiceFactory:
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
@@ -119,6 +123,7 @@ PrivateVerificationTokensServiceFactory:
     }
   }
   return service;
+#endif
 }
 
 bool PrivateVerificationTokensServiceFactory::
