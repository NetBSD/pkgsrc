$NetBSD: patch-src_network_ssl_qsslsocket__openssl__symbols__p.h,v 1.5 2018/01/17 18:37:34 markd Exp $

* fixes build with OpenSSL 0.9.9-dev
* fix build with -openssl-linked for OpenSSL 0.9.8*
  http://qt.gitorious.org/qt/qt/commit/4db91cbd6147e40f543342f22c05b7baddc52e5a
* Compile with openssl-1.1.0 http://bugs.debian.org/828522 via archlinux

--- src/network/ssl/qsslsocket_openssl_symbols_p.h.orig	2015-05-07 14:14:44.000000000 +0000
+++ src/network/ssl/qsslsocket_openssl_symbols_p.h
@@ -59,6 +59,9 @@
 QT_BEGIN_NAMESPACE
 
 #define DUMMYARG
+#ifndef OPENSSL_NO_SSL2
+#define OPENSSL_NO_SSL2 1
+#endif
 
 #if !defined QT_LINKED_OPENSSL
 // **************** Shared declarations ******************
@@ -207,16 +210,24 @@ int q_ASN1_STRING_length(ASN1_STRING *a)
 int q_ASN1_STRING_to_UTF8(unsigned char **a, ASN1_STRING *b);
 long q_BIO_ctrl(BIO *a, int b, long c, void *d);
 int q_BIO_free(BIO *a);
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+BIO *q_BIO_new(const BIO_METHOD *a);
+#else
 BIO *q_BIO_new(BIO_METHOD *a);
+#endif
 BIO *q_BIO_new_mem_buf(void *a, int b);
 int q_BIO_read(BIO *a, void *b, int c);
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+const BIO_METHOD *q_BIO_s_mem();
+#else
 BIO_METHOD *q_BIO_s_mem();
+#endif
 int q_BIO_write(BIO *a, const void *b, int c);
 int q_BN_num_bits(const BIGNUM *a);
 int q_CRYPTO_num_locks();
 void q_CRYPTO_set_locking_callback(void (*a)(int, int, const char *, int));
 void q_CRYPTO_set_id_callback(unsigned long (*a)());
-void q_CRYPTO_free(void *a);
+void q_OPENSSL_free(void *a);
 void q_DSA_free(DSA *a);
 #if OPENSSL_VERSION_NUMBER >= 0x00908000L
 // 0.9.8 broke SC and BC by changing this function's signature.
@@ -279,7 +290,7 @@ int q_SSL_CTX_check_private_key(SSL_CTX 
 #endif
 long q_SSL_CTX_ctrl(SSL_CTX *a, int b, long c, void *d);
 void q_SSL_CTX_free(SSL_CTX *a);
-#if OPENSSL_VERSION_NUMBER >= 0x10000000L
+#if OPENSSL_VERSION_NUMBER >= 0x00909000L
 SSL_CTX *q_SSL_CTX_new(const SSL_METHOD *a);
 #else
 SSL_CTX *q_SSL_CTX_new(SSL_METHOD *a);
@@ -325,8 +336,7 @@ void q_SSL_set_bio(SSL *a, BIO *b, BIO *
 void q_SSL_set_accept_state(SSL *a);
 void q_SSL_set_connect_state(SSL *a);
 int q_SSL_shutdown(SSL *a);
-#if OPENSSL_VERSION_NUMBER >= 0x10000000L
-const SSL_METHOD *q_SSLv2_client_method();
+#if OPENSSL_VERSION_NUMBER >= 0x00909000L
 const SSL_METHOD *q_SSLv3_client_method();
 const SSL_METHOD *q_SSLv23_client_method();
 const SSL_METHOD *q_TLSv1_client_method();
@@ -335,7 +345,6 @@ const SSL_METHOD *q_SSLv3_server_method(
 const SSL_METHOD *q_SSLv23_server_method();
 const SSL_METHOD *q_TLSv1_server_method();
 #else
-SSL_METHOD *q_SSLv2_client_method();
 SSL_METHOD *q_SSLv3_client_method();
 SSL_METHOD *q_SSLv23_client_method();
 SSL_METHOD *q_TLSv1_client_method();
@@ -399,7 +408,25 @@ DSA *q_d2i_DSAPrivateKey(DSA **a, unsign
 		PEM_ASN1_write_bio((int (*)(void*, unsigned char**))q_i2d_DSAPrivateKey,PEM_STRING_DSA,\
 			bp,(char *)x,enc,kstr,klen,cb,u)
 #endif
+
+X509_STORE * q_SSL_CTX_get_cert_store(const SSL_CTX *ctx);
+ASN1_INTEGER * q_X509_get_serialNumber(X509 *x);
+
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
 #define q_SSL_CTX_set_options(ctx,op) q_SSL_CTX_ctrl((ctx),SSL_CTRL_OPTIONS,(op),NULL)
+#define q_X509_get_version(x) X509_get_version(x)
+#else
+int q_EVP_PKEY_id(const EVP_PKEY *pkey);
+int q_EVP_PKEY_base_id(const EVP_PKEY *pkey);
+int q_SSL_CIPHER_get_bits(const SSL_CIPHER *cipher, int *alg_bits);
+long q_SSL_CTX_set_options(SSL_CTX *ctx, long options);
+long q_X509_get_version(X509 *x);
+X509_PUBKEY * q_X509_get_X509_PUBKEY(X509 *x);
+int q_RSA_bits(const RSA *rsa);
+int q_DSA_security_bits(const DSA *dsa);
+void q_DSA_get0_pqg(const DSA *d, const BIGNUM **p, const BIGNUM **q, const BIGNUM **g);
+#endif
+
 #define q_SKM_sk_num(type, st) ((int (*)(const STACK_OF(type) *))q_sk_num)(st)
 #define q_SKM_sk_value(type, st,i) ((type * (*)(const STACK_OF(type) *, int))q_sk_value)(st, i)
 #define q_sk_GENERAL_NAME_num(st) q_SKM_sk_num(GENERAL_NAME, (st))
@@ -410,8 +437,15 @@ DSA *q_d2i_DSAPrivateKey(DSA **a, unsign
 #define q_sk_SSL_CIPHER_value(st, i) q_SKM_sk_value(SSL_CIPHER, (st), (i))
 #define q_SSL_CTX_add_extra_chain_cert(ctx,x509) \
         q_SSL_CTX_ctrl(ctx,SSL_CTRL_EXTRA_CHAIN_CERT,0,(char *)x509)
+
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
 #define q_X509_get_notAfter(x) X509_get_notAfter(x)
 #define q_X509_get_notBefore(x) X509_get_notBefore(x)
+#else
+ASN1_TIME *q_X509_get_notAfter(X509 *x);
+ASN1_TIME *q_X509_get_notBefore(X509 *x);
+#endif
+
 #define q_EVP_PKEY_assign_RSA(pkey,rsa) q_EVP_PKEY_assign((pkey),EVP_PKEY_RSA,\
 					(char *)(rsa))
 #define q_EVP_PKEY_assign_DSA(pkey,dsa) q_EVP_PKEY_assign((pkey),EVP_PKEY_DSA,\
