$NetBSD: patch-buckets_ssl__buckets.c,v 1.3 2023/01/12 11:44:48 markd Exp $

openssl3 patch

--- buckets/ssl_buckets.c.orig	2016-06-30 15:45:07.000000000 +0000
+++ buckets/ssl_buckets.c
@@ -1204,6 +1204,10 @@ static void init_ssl_libraries(void)
     }
 }
 
+#ifndef ERR_GET_FUNC
+#define ERR_GET_FUNC(ec) (0)
+#endif
+
 static int ssl_need_client_cert(SSL *ssl, X509 **cert, EVP_PKEY **pkey)
 {
     serf_ssl_context_t *ctx = SSL_get_app_data(ssl);
