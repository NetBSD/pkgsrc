$NetBSD: patch-src_network_ssl_qsslsocket__openssl__symbols.cpp,v 1.5 2012/12/07 10:06:13 adam Exp $

* fixes build with OpenSSL 0.9.9-dev
* fix build with -openssl-linked for OpenSSL 0.9.8*
  http://qt.gitorious.org/qt/qt/commit/4db91cbd6147e40f543342f22c05b7baddc52e5a

--- src/network/ssl/qsslsocket_openssl_symbols.cpp.orig	2012-03-14 14:01:30.000000000 +0000
+++ src/network/ssl/qsslsocket_openssl_symbols.cpp
@@ -174,7 +174,7 @@ DEFINEFUNC(int, SSL_CTX_check_private_ke
 #endif
 DEFINEFUNC4(long, SSL_CTX_ctrl, SSL_CTX *a, a, int b, b, long c, c, void *d, d, return -1, return)
 DEFINEFUNC(void, SSL_CTX_free, SSL_CTX *a, a, return, DUMMYARG)
-#if OPENSSL_VERSION_NUMBER >= 0x10000000L
+#if OPENSSL_VERSION_NUMBER >= 0x00909000L
 DEFINEFUNC(SSL_CTX *, SSL_CTX_new, const SSL_METHOD *a, a, return 0, return)
 #else
 DEFINEFUNC(SSL_CTX *, SSL_CTX_new, SSL_METHOD *a, a, return 0, return)
@@ -220,7 +220,7 @@ DEFINEFUNC3(void, SSL_set_bio, SSL *a, a
 DEFINEFUNC(void, SSL_set_accept_state, SSL *a, a, return, DUMMYARG)
 DEFINEFUNC(void, SSL_set_connect_state, SSL *a, a, return, DUMMYARG)
 DEFINEFUNC(int, SSL_shutdown, SSL *a, a, return -1, return)
-#if OPENSSL_VERSION_NUMBER >= 0x10000000L
+#if OPENSSL_VERSION_NUMBER >= 0x00909000L
 #ifndef OPENSSL_NO_SSL2
 DEFINEFUNC(const SSL_METHOD *, SSLv2_client_method, DUMMYARG, DUMMYARG, return 0, return)
 #endif
