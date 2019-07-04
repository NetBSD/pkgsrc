$NetBSD: patch-src_network_ssl_socket.c,v 1.1 2019/07/04 12:15:04 nia Exp $

Support OpenSSL 1.1.

Derived from FreeBSD Ports.

--- src/network/ssl/socket.c.orig	2012-10-28 12:57:15.000000000 +0000
+++ src/network/ssl/socket.c
@@ -67,7 +67,7 @@ static void
 ssl_set_no_tls(struct socket *socket)
 {
 #ifdef CONFIG_OPENSSL
-	((ssl_t *) socket->ssl)->options |= SSL_OP_NO_TLSv1;
+	SSL_set_options((ssl_t *) socket->ssl, SSL_OP_NO_TLSv1);
 #elif defined(CONFIG_GNUTLS)
 	{
 		/* GnuTLS does not support SSLv2 because it is "insecure".
@@ -145,7 +145,7 @@ ssl_connect(struct socket *socket)
 		}
 
 		if (client_cert) {
-			SSL_CTX *ctx = ((SSL *) socket->ssl)->ctx;
+			SSL_CTX *ctx = SSL_get_SSL_CTX(socket->ssl);
 
 			SSL_CTX_use_certificate_chain_file(ctx, client_cert);
 			SSL_CTX_use_PrivateKey_file(ctx, client_cert,
