$NetBSD: patch-src_network_ssl_qsslsocket__openssl__symbols.cpp,v 1.2 2012/01/12 22:59:58 adam Exp $

--- src/network/ssl/qsslsocket_openssl_symbols.cpp.orig	2011-12-08 05:06:02.000000000 +0000
+++ src/network/ssl/qsslsocket_openssl_symbols.cpp
@@ -171,7 +171,7 @@ DEFINEFUNC(int, SSL_CTX_check_private_ke
 #endif
 DEFINEFUNC4(long, SSL_CTX_ctrl, SSL_CTX *a, a, int b, b, long c, c, void *d, d, return -1, return)
 DEFINEFUNC(void, SSL_CTX_free, SSL_CTX *a, a, return, DUMMYARG)
-#if OPENSSL_VERSION_NUMBER >= 0x10000000L
+#if OPENSSL_VERSION_NUMBER >= 0x00909000L
 DEFINEFUNC(SSL_CTX *, SSL_CTX_new, const SSL_METHOD *a, a, return 0, return)
 #else
 DEFINEFUNC(SSL_CTX *, SSL_CTX_new, SSL_METHOD *a, a, return 0, return)
@@ -213,7 +213,7 @@ DEFINEFUNC(SSL *, SSL_new, SSL_CTX *a, a
 #if OPENSSL_VERSION_NUMBER >= 0x10000000L
 DEFINEFUNC4(long, SSL_ctrl, SSL *a, a, int cmd, cmd, long larg, larg, void *parg, parg, return -1, return)
 #else
-DEFINEFUNC4(long, SSL_ctrl, SSL *a, a, int cmd, cmd, long larg, larg, const void *parg, parg, return -1, return)
+DEFINEFUNC4(long, SSL_ctrl, SSL *a, a, int cmd, cmd, long larg, larg, void *parg, parg, return -1, return)
 #endif
 #endif
 DEFINEFUNC3(int, SSL_read, SSL *a, a, void *b, b, int c, c, return -1, return)
@@ -221,7 +221,7 @@ DEFINEFUNC3(void, SSL_set_bio, SSL *a, a
 DEFINEFUNC(void, SSL_set_accept_state, SSL *a, a, return, DUMMYARG)
 DEFINEFUNC(void, SSL_set_connect_state, SSL *a, a, return, DUMMYARG)
 DEFINEFUNC(int, SSL_shutdown, SSL *a, a, return -1, return)
-#if OPENSSL_VERSION_NUMBER >= 0x10000000L
+#if OPENSSL_VERSION_NUMBER >= 0x00909000L
 #ifndef OPENSSL_NO_SSL2
 DEFINEFUNC(const SSL_METHOD *, SSLv2_client_method, DUMMYARG, DUMMYARG, return 0, return)
 #endif
