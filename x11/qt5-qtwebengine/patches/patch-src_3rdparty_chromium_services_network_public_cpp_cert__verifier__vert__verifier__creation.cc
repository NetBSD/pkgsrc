$NetBSD: patch-src_3rdparty_chromium_services_network_public_cpp_cert__verifier__vert__verifier__creation.cc,v 1.1 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/services/network/public/cpp/cert_verifier/cert_verifier_creation.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/services/network/public/cpp/cert_verifier/cert_verifier_creation.cc
@@ -70,7 +70,7 @@ scoped_refptr<net::CertVerifyProc> Creat
 
 bool IsUsingCertNetFetcher() {
 #if defined(OS_ANDROID) || defined(OS_FUCHSIA) || defined(OS_CHROMEOS) || \
-    defined(OS_LINUX) ||                                                  \
+    defined(OS_LINUX) || defined(OS_BSD) ||                               \
     BUILDFLAG(TRIAL_COMPARISON_CERT_VERIFIER_SUPPORTED) ||                \
     BUILDFLAG(BUILTIN_CERT_VERIFIER_FEATURE_SUPPORTED)
   return true;
