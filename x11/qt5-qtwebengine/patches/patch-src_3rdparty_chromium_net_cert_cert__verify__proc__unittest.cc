$NetBSD: patch-src_3rdparty_chromium_net_cert_cert__verify__proc__unittest.cc,v 1.1 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/net/cert/cert_verify_proc_unittest.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/net/cert/cert_verify_proc_unittest.cc
@@ -221,7 +221,7 @@ const std::vector<CertVerifyProcType> kA
     CERT_VERIFY_PROC_MAC, CERT_VERIFY_PROC_BUILTIN
 #elif defined(OS_WIN)
     CERT_VERIFY_PROC_WIN
-#elif defined(OS_FUCHSIA) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#elif defined(OS_FUCHSIA) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
     CERT_VERIFY_PROC_BUILTIN
 #else
 #error Unsupported platform
