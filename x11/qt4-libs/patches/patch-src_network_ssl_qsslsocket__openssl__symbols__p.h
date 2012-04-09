$NetBSD: patch-src_network_ssl_qsslsocket__openssl__symbols__p.h,v 1.4 2012/04/09 09:12:49 adam Exp $

* fixes build with OpenSSL 0.9.9-dev
* fix build with -openssl-linked for OpenSSL 0.9.8*
  http://qt.gitorious.org/qt/qt/commit/4db91cbd6147e40f543342f22c05b7baddc52e5a

--- src/network/ssl/qsslsocket_openssl_symbols_p.h.orig	2012-03-14 14:01:30.000000000 +0000
+++ src/network/ssl/qsslsocket_openssl_symbols_p.h
@@ -279,7 +279,7 @@ int q_SSL_CTX_check_private_key(SSL_CTX 
 #endif
 long q_SSL_CTX_ctrl(SSL_CTX *a, int b, long c, void *d);
 void q_SSL_CTX_free(SSL_CTX *a);
-#if OPENSSL_VERSION_NUMBER >= 0x10000000L
+#if OPENSSL_VERSION_NUMBER >= 0x00909000L
 SSL_CTX *q_SSL_CTX_new(const SSL_METHOD *a);
 #else
 SSL_CTX *q_SSL_CTX_new(SSL_METHOD *a);
@@ -325,7 +325,7 @@ void q_SSL_set_bio(SSL *a, BIO *b, BIO *
 void q_SSL_set_accept_state(SSL *a);
 void q_SSL_set_connect_state(SSL *a);
 int q_SSL_shutdown(SSL *a);
-#if OPENSSL_VERSION_NUMBER >= 0x10000000L
+#if OPENSSL_VERSION_NUMBER >= 0x00909000L
 const SSL_METHOD *q_SSLv2_client_method();
 const SSL_METHOD *q_SSLv3_client_method();
 const SSL_METHOD *q_SSLv23_client_method();
