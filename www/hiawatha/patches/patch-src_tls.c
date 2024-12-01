$NetBSD: patch-src_tls.c,v 1.1 2024/12/01 22:30:06 hauke Exp $

TLS v1.3 support is partly broken in mbedtls 3.6, see
<https://github.com/Mbed-TLS/mbedtls/issues/9223>

Since there is no configuration option for limiting the TLS version,
disable until upstream updates the enclosed mbedtls.

--- src/tls.c.orig	2024-12-01 20:57:08.785456125 +0000
+++ src/tls.c
@@ -242,7 +242,7 @@ int tls_set_config(mbedtls_ssl_config **
 	}
 
 	mbedtls_ssl_conf_min_tls_version(*tls_config, MBEDTLS_SSL_VERSION_TLS1_2);
-	mbedtls_ssl_conf_max_tls_version(*tls_config, MBEDTLS_SSL_VERSION_TLS1_3);
+	mbedtls_ssl_conf_max_tls_version(*tls_config, MBEDTLS_SSL_VERSION_TLS1_2);
 
 	mbedtls_ssl_conf_renegotiation(*tls_config, MBEDTLS_SSL_RENEGOTIATION_DISABLED);
 	mbedtls_ssl_conf_rng(*tls_config, tls_random, &ctr_drbg);
