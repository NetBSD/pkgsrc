$NetBSD: patch-src_network_ssl_qsslsocket__openssl__symbols.cpp,v 1.6 2018/01/17 18:37:34 markd Exp $

* fixes build with OpenSSL 0.9.9-dev
* fix build with -openssl-linked for OpenSSL 0.9.8*
  http://qt.gitorious.org/qt/qt/commit/4db91cbd6147e40f543342f22c05b7baddc52e5a
* react to OPENSSL_NO_SSL3
* Compile with openssl-1.1.0 http://bugs.debian.org/828522 via archlinux

--- src/network/ssl/qsslsocket_openssl_symbols.cpp.orig	2015-05-07 14:14:44.000000000 +0000
+++ src/network/ssl/qsslsocket_openssl_symbols.cpp
@@ -111,16 +111,24 @@ DEFINEFUNC(int, ASN1_STRING_length, ASN1
 DEFINEFUNC2(int, ASN1_STRING_to_UTF8, unsigned char **a, a, ASN1_STRING *b, b, return 0, return);
 DEFINEFUNC4(long, BIO_ctrl, BIO *a, a, int b, b, long c, c, void *d, d, return -1, return)
 DEFINEFUNC(int, BIO_free, BIO *a, a, return 0, return)
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+DEFINEFUNC(BIO *, BIO_new, const BIO_METHOD *a, a, return 0, return)
+#else
 DEFINEFUNC(BIO *, BIO_new, BIO_METHOD *a, a, return 0, return)
+#endif
 DEFINEFUNC2(BIO *, BIO_new_mem_buf, void *a, a, int b, b, return 0, return)
 DEFINEFUNC3(int, BIO_read, BIO *a, a, void *b, b, int c, c, return -1, return)
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+DEFINEFUNC(const BIO_METHOD *, BIO_s_mem, void, DUMMYARG, return 0, return)
+#else
 DEFINEFUNC(BIO_METHOD *, BIO_s_mem, void, DUMMYARG, return 0, return)
+#endif
 DEFINEFUNC3(int, BIO_write, BIO *a, a, const void *b, b, int c, c, return -1, return)
 DEFINEFUNC(int, BN_num_bits, const BIGNUM *a, a, return 0, return)
 DEFINEFUNC(int, CRYPTO_num_locks, DUMMYARG, DUMMYARG, return 0, return)
 DEFINEFUNC(void, CRYPTO_set_locking_callback, void (*a)(int, int, const char *, int), a, return, DUMMYARG)
 DEFINEFUNC(void, CRYPTO_set_id_callback, unsigned long (*a)(), a, return, DUMMYARG)
-DEFINEFUNC(void, CRYPTO_free, void *a, a, return, DUMMYARG)
+DEFINEFUNC(void, OPENSSL_free, void *a, a, return, DUMMYARG)
 DEFINEFUNC(void, DSA_free, DSA *a, a, return, DUMMYARG)
 #if  OPENSSL_VERSION_NUMBER < 0x00908000L
 DEFINEFUNC3(X509 *, d2i_X509, X509 **a, a, unsigned char **b, b, long c, c, return 0, return)
@@ -178,7 +186,7 @@ DEFINEFUNC(int, SSL_CTX_check_private_ke
 #endif
 DEFINEFUNC4(long, SSL_CTX_ctrl, SSL_CTX *a, a, int b, b, long c, c, void *d, d, return -1, return)
 DEFINEFUNC(void, SSL_CTX_free, SSL_CTX *a, a, return, DUMMYARG)
-#if OPENSSL_VERSION_NUMBER >= 0x10000000L
+#if OPENSSL_VERSION_NUMBER >= 0x00909000L
 DEFINEFUNC(SSL_CTX *, SSL_CTX_new, const SSL_METHOD *a, a, return 0, return)
 #else
 DEFINEFUNC(SSL_CTX *, SSL_CTX_new, SSL_METHOD *a, a, return 0, return)
@@ -224,17 +232,21 @@ DEFINEFUNC3(void, SSL_set_bio, SSL *a, a
 DEFINEFUNC(void, SSL_set_accept_state, SSL *a, a, return, DUMMYARG)
 DEFINEFUNC(void, SSL_set_connect_state, SSL *a, a, return, DUMMYARG)
 DEFINEFUNC(int, SSL_shutdown, SSL *a, a, return -1, return)
-#if OPENSSL_VERSION_NUMBER >= 0x10000000L
+#if OPENSSL_VERSION_NUMBER >= 0x00909000L
 #ifndef OPENSSL_NO_SSL2
 DEFINEFUNC(const SSL_METHOD *, SSLv2_client_method, DUMMYARG, DUMMYARG, return 0, return)
 #endif
+#ifndef OPENSSL_NO_SSL3
 DEFINEFUNC(const SSL_METHOD *, SSLv3_client_method, DUMMYARG, DUMMYARG, return 0, return)
+#endif
 DEFINEFUNC(const SSL_METHOD *, SSLv23_client_method, DUMMYARG, DUMMYARG, return 0, return)
 DEFINEFUNC(const SSL_METHOD *, TLSv1_client_method, DUMMYARG, DUMMYARG, return 0, return)
 #ifndef OPENSSL_NO_SSL2
 DEFINEFUNC(const SSL_METHOD *, SSLv2_server_method, DUMMYARG, DUMMYARG, return 0, return)
 #endif
+#ifndef OPENSSL_NO_SSL3
 DEFINEFUNC(const SSL_METHOD *, SSLv3_server_method, DUMMYARG, DUMMYARG, return 0, return)
+#endif
 DEFINEFUNC(const SSL_METHOD *, SSLv23_server_method, DUMMYARG, DUMMYARG, return 0, return)
 DEFINEFUNC(const SSL_METHOD *, TLSv1_server_method, DUMMYARG, DUMMYARG, return 0, return)
 #else
@@ -286,6 +298,22 @@ DEFINEFUNC(void, OPENSSL_add_all_algorit
 DEFINEFUNC(void, OPENSSL_add_all_algorithms_conf, void, DUMMYARG, return, DUMMYARG)
 DEFINEFUNC3(int, SSL_CTX_load_verify_locations, SSL_CTX *ctx, ctx, const char *CAfile, CAfile, const char *CApath, CApath, return 0, return)
 DEFINEFUNC(long, SSLeay, void, DUMMYARG, return 0, return)
+DEFINEFUNC(X509_STORE *, SSL_CTX_get_cert_store, const SSL_CTX *ctx, ctx, return 0, return)
+
+DEFINEFUNC(ASN1_INTEGER *, X509_get_serialNumber, X509 *x, x, return 0, return)
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+DEFINEFUNC(int, EVP_PKEY_id, const EVP_PKEY *pkey, pkey, return 0, return)
+DEFINEFUNC(int, EVP_PKEY_base_id, const EVP_PKEY *pkey, pkey, return 0, return)
+DEFINEFUNC2(int, SSL_CIPHER_get_bits, const SSL_CIPHER *cipher, cipher, int *alg_bits, alg_bits, return 0, return)
+DEFINEFUNC2(long, SSL_CTX_set_options, SSL_CTX *ctx, ctx, long options, options, return 0, return)
+DEFINEFUNC(long, X509_get_version, X509 *x, x, return 0, return)
+DEFINEFUNC(X509_PUBKEY *, X509_get_X509_PUBKEY, X509 *x, x, return 0, return)
+DEFINEFUNC(int, RSA_bits,  const RSA *rsa, rsa, return 0, return)
+DEFINEFUNC(int, DSA_security_bits, const DSA *dsa, dsa, return 0, return)
+DEFINEFUNC(ASN1_TIME *, X509_get_notAfter, X509 *x, x, return 0, return)
+DEFINEFUNC(ASN1_TIME *, X509_get_notBefore, X509 *x, x, return 0, return)
+DEFINEFUNC4(void, DSA_get0_pqg, const DSA *d, d, const BIGNUM **p, p, const BIGNUM **q, q, const BIGNUM **g, g, return, return)
+#endif
 
 #ifdef Q_OS_SYMBIAN
 #define RESOLVEFUNC(func, ordinal, lib) \
@@ -797,6 +825,7 @@ bool q_resolveOpenSslSymbols()
     RESOLVEFUNC(SSL_CTX_use_PrivateKey)
     RESOLVEFUNC(SSL_CTX_use_RSAPrivateKey)
     RESOLVEFUNC(SSL_CTX_use_PrivateKey_file)
+    RESOLVEFUNC(SSL_CTX_get_cert_store)
     RESOLVEFUNC(SSL_accept)
     RESOLVEFUNC(SSL_clear)
     RESOLVEFUNC(SSL_connect)
@@ -819,16 +848,37 @@ bool q_resolveOpenSslSymbols()
     RESOLVEFUNC(SSL_set_connect_state)
     RESOLVEFUNC(SSL_shutdown)
     RESOLVEFUNC(SSL_write)
+
+    RESOLVEFUNC(X509_get_serialNumber)
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+    RESOLVEFUNC(SSL_CTX_ctrl)
+    RESOLVEFUNC(EVP_PKEY_id)
+    RESOLVEFUNC(EVP_PKEY_base_id)
+    RESOLVEFUNC(SSL_CIPHER_get_bits)
+    RESOLVEFUNC(SSL_CTX_set_options)
+    RESOLVEFUNC(X509_get_version)
+    RESOLVEFUNC(X509_get_X509_PUBKEY)
+    RESOLVEFUNC(RSA_bits)
+    RESOLVEFUNC(DSA_security_bits)
+    RESOLVEFUNC(DSA_get0_pqg)
+    RESOLVEFUNC(X509_get_notAfter)
+    RESOLVEFUNC(X509_get_notBefore)
+#endif
+
 #ifndef OPENSSL_NO_SSL2
     RESOLVEFUNC(SSLv2_client_method)
 #endif
+#ifndef OPENSSL_NO_SSL3
     RESOLVEFUNC(SSLv3_client_method)
+#endif
     RESOLVEFUNC(SSLv23_client_method)
     RESOLVEFUNC(TLSv1_client_method)
 #ifndef OPENSSL_NO_SSL2
     RESOLVEFUNC(SSLv2_server_method)
 #endif
+#ifndef OPENSSL_NO_SSL3
     RESOLVEFUNC(SSLv3_server_method)
+#endif
     RESOLVEFUNC(SSLv23_server_method)
     RESOLVEFUNC(TLSv1_server_method)
     RESOLVEFUNC(X509_NAME_entry_count)
