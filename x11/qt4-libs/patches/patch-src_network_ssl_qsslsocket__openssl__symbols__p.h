$NetBSD: patch-src_network_ssl_qsslsocket__openssl__symbols__p.h,v 1.3 2012/01/14 10:23:18 obache Exp $

* fixes build with OpenSSL 0.9.9-dev
* fix build with -openssl-linked for OpenSSL 0.9.8*
  http://qt.gitorious.org/qt/qt/commit/4db91cbd6147e40f543342f22c05b7baddc52e5a


--- src/network/ssl/qsslsocket_openssl_symbols_p.h.orig	2011-12-08 05:06:02.000000000 +0000
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
@@ -318,18 +318,14 @@ int q_SSL_library_init();
 void q_SSL_load_error_strings();
 SSL *q_SSL_new(SSL_CTX *a);
 #if OPENSSL_VERSION_NUMBER >= 0x0090806fL && !defined(OPENSSL_NO_TLSEXT)
-#if OPENSSL_VERSION_NUMBER >= 0x10000000L
 long q_SSL_ctrl(SSL *ssl,int cmd, long larg, void *parg);
-#else
-long q_SSL_ctrl(SSL *ssl,int cmd, long larg, const void *parg);
-#endif
 #endif
 int q_SSL_read(SSL *a, void *b, int c);
 void q_SSL_set_bio(SSL *a, BIO *b, BIO *c);
 void q_SSL_set_accept_state(SSL *a);
 void q_SSL_set_connect_state(SSL *a);
 int q_SSL_shutdown(SSL *a);
-#if OPENSSL_VERSION_NUMBER >= 0x10000000L
+#if OPENSSL_VERSION_NUMBER >= 0x00909000L
 const SSL_METHOD *q_SSLv2_client_method();
 const SSL_METHOD *q_SSLv3_client_method();
 const SSL_METHOD *q_SSLv23_client_method();
