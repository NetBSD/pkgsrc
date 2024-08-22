$NetBSD: patch-mbedtls_library_ssl_tls13_generic.c,v 1.1 2024/08/22 15:59:21 hauke Exp $

Fix compilation where memcpy as a function-like macro, from
<https://github.com/tom-cosgrove-arm/mbedtls/commit/b32d7ae0fee2f906be59780b42a0cd4468a39bd1>

--- mbedtls/library/ssl_tls13_generic.c.orig	2024-08-22 15:00:42.358144005 +0000
+++ mbedtls/library/ssl_tls13_generic.c
@@ -193,10 +193,12 @@ static void ssl_tls13_create_verify_stru
     idx = 64;
 
     if (from == MBEDTLS_SSL_IS_CLIENT) {
-        memcpy(verify_buffer + idx, MBEDTLS_SSL_TLS1_3_LBL_WITH_LEN(client_cv));
+        memcpy(verify_buffer + idx, mbedtls_ssl_tls13_labels.client_cv,
+               MBEDTLS_SSL_TLS1_3_LBL_LEN(client_cv));
         idx += MBEDTLS_SSL_TLS1_3_LBL_LEN(client_cv);
     } else { /* from == MBEDTLS_SSL_IS_SERVER */
-        memcpy(verify_buffer + idx, MBEDTLS_SSL_TLS1_3_LBL_WITH_LEN(server_cv));
+        memcpy(verify_buffer + idx, mbedtls_ssl_tls13_labels.client_cv,
+               MBEDTLS_SSL_TLS1_3_LBL_LEN(client_cv));
         idx += MBEDTLS_SSL_TLS1_3_LBL_LEN(server_cv);
     }
 
