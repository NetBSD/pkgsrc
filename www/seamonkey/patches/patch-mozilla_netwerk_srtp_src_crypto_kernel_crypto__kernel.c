$NetBSD: patch-mozilla_netwerk_srtp_src_crypto_kernel_crypto__kernel.c,v 1.1 2020/05/06 14:34:53 ryoon Exp $

--- mozilla/netwerk/srtp/src/crypto/kernel/crypto_kernel.c.orig	2020-02-17 23:38:00.000000000 +0000
+++ mozilla/netwerk/srtp/src/crypto/kernel/crypto_kernel.c
@@ -77,7 +77,7 @@ extern cipher_type_t aes_cbc;
  */
 
 extern auth_type_t null_auth;
-extern auth_type_t hmac;
+extern auth_type_t hmac_auth;
 
 /* crypto_kernel is a global variable, the only one of its datatype */
 
@@ -162,7 +162,7 @@ crypto_kernel_init() {
   status = crypto_kernel_load_auth_type(&null_auth, NULL_AUTH);
   if (status)
     return status;
-  status = crypto_kernel_load_auth_type(&hmac, HMAC_SHA1);
+  status = crypto_kernel_load_auth_type(&hmac_auth, HMAC_SHA1);
   if (status)
     return status;
 
