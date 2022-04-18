$NetBSD: patch-src_3rdparty_chromium_net_cert_cert__verify__proc.cc,v 1.1 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/net/cert/cert_verify_proc.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/net/cert/cert_verify_proc.cc
@@ -493,7 +493,7 @@ base::Value CertVerifyParams(X509Certifi
 
 }  // namespace
 
-#if !(defined(OS_FUCHSIA) || defined(OS_LINUX) || defined(OS_CHROMEOS))
+#if !(defined(OS_FUCHSIA) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD))
 // static
 scoped_refptr<CertVerifyProc> CertVerifyProc::CreateSystemVerifyProc(
     scoped_refptr<CertNetFetcher> cert_net_fetcher) {
