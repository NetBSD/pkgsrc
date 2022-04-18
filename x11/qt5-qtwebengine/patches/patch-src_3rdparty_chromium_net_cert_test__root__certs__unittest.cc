$NetBSD: patch-src_3rdparty_chromium_net_cert_test__root__certs__unittest.cc,v 1.1 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/net/cert/test_root_certs_unittest.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/net/cert/test_root_certs_unittest.cc
@@ -33,7 +33,7 @@ const char kRootCertificateFile[] = "roo
 const char kGoodCertificateFile[] = "ok_cert.pem";
 
 scoped_refptr<CertVerifyProc> CreateCertVerifyProc() {
-#if defined(OS_FUCHSIA) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_FUCHSIA) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   return CertVerifyProc::CreateBuiltinVerifyProc(/*cert_net_fetcher=*/nullptr);
 #elif BUILDFLAG(BUILTIN_CERT_VERIFIER_FEATURE_SUPPORTED)
   if (base::FeatureList::IsEnabled(features::kCertVerifierBuiltinFeature)) {
