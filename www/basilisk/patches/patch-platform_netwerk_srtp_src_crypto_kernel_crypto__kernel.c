$NetBSD: patch-platform_netwerk_srtp_src_crypto_kernel_crypto__kernel.c,v 1.1 2025/04/25 21:25:03 nia Exp $

NetBSD has a libc symbol called hmac.

--- platform/netwerk/srtp/src/crypto/kernel/crypto_kernel.c.orig	2025-04-24 11:18:08.323474546 +0000
+++ platform/netwerk/srtp/src/crypto/kernel/crypto_kernel.c
@@ -77,7 +77,7 @@ extern cipher_type_t aes_cbc;
  */
 
 extern auth_type_t null_auth;
-extern auth_type_t hmac;
+extern auth_type_t my_hmac;
 
 /* crypto_kernel is a global variable, the only one of its datatype */
 
@@ -162,7 +162,7 @@ crypto_kernel_init() {
   status = crypto_kernel_load_auth_type(&null_auth, NULL_AUTH);
   if (status)
     return status;
-  status = crypto_kernel_load_auth_type(&hmac, HMAC_SHA1);
+  status = crypto_kernel_load_auth_type(&my_hmac, HMAC_SHA1);
   if (status)
     return status;
 
