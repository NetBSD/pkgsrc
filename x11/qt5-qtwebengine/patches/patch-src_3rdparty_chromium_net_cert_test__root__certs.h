$NetBSD: patch-src_3rdparty_chromium_net_cert_test__root__certs.h,v 1.1 2022/04/18 11:18:19 adam Exp $

--- src/3rdparty/chromium/net/cert/test_root_certs.h.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/net/cert/test_root_certs.h
@@ -75,7 +75,7 @@ class NET_EXPORT TestRootCerts {
   // engine is appropriate. The caller is responsible for freeing the
   // returned HCERTCHAINENGINE.
   HCERTCHAINENGINE GetChainEngine() const;
-#elif defined(OS_FUCHSIA) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#elif defined(OS_FUCHSIA) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   TrustStore* test_trust_store() { return &test_trust_store_; }
 #endif
 
@@ -93,12 +93,12 @@ class NET_EXPORT TestRootCerts {
 #elif defined(OS_APPLE)
   base::ScopedCFTypeRef<CFMutableArrayRef> temporary_roots_;
   TrustStoreInMemory test_trust_store_;
-#elif defined(OS_FUCHSIA) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#elif defined(OS_FUCHSIA) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   TrustStoreInMemory test_trust_store_;
 #endif
 
 #if defined(OS_WIN) || defined(OS_ANDROID) || defined(OS_FUCHSIA) || \
-    defined(OS_LINUX) || defined(OS_CHROMEOS)
+    defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // True if there are no temporarily trusted root certificates.
   bool empty_ = true;
 #endif
