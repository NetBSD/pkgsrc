$NetBSD: patch-netwerk_srtp_src_crypto_kernel_crypto__kernel.c,v 1.1 2016/10/30 01:06:26 kamil Exp $

Fix conflicting hmac symbol name with <stdlib.h> on NetBSD.

--- netwerk/srtp/src/crypto/kernel/crypto_kernel.c.orig	2016-05-12 17:13:29.000000000 +0000
+++ netwerk/srtp/src/crypto/kernel/crypto_kernel.c
@@ -77,7 +77,7 @@ extern cipher_type_t aes_cbc;
  */
 
 extern auth_type_t null_auth;
-extern auth_type_t hmac;
+extern auth_type_t ffhmac;
 
 /* crypto_kernel is a global variable, the only one of its datatype */
 
@@ -162,7 +162,7 @@ crypto_kernel_init() {
   status = crypto_kernel_load_auth_type(&null_auth, NULL_AUTH);
   if (status)
     return status;
-  status = crypto_kernel_load_auth_type(&hmac, HMAC_SHA1);
+  status = crypto_kernel_load_auth_type(&ffhmac, HMAC_SHA1);
   if (status)
     return status;
 
