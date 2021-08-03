$NetBSD: patch-src_3rdparty_chromium_third__party_boringssl_src_include_openssl_thread.h,v 1.1 2021/08/03 21:04:36 markd Exp $

--- src/3rdparty/chromium/third_party/boringssl/src/include/openssl/thread.h.orig	2020-06-25 09:34:42.000000000 +0000
+++ src/3rdparty/chromium/third_party/boringssl/src/include/openssl/thread.h
@@ -88,6 +88,9 @@ typedef pthread_rwlock_t CRYPTO_MUTEX;
 typedef union crypto_mutex_st {
   double alignment;
   uint8_t padding[3*sizeof(int) + 5*sizeof(unsigned) + 16 + 8];
+#if defined(__NetBSD__)
+  uint8_t      nbpad[64 + 8];
+#endif
 } CRYPTO_MUTEX;
 #endif
 
