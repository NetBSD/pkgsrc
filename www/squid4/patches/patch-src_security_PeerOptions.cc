$NetBSD: patch-src_security_PeerOptions.cc,v 1.1 2025/01/27 11:39:15 wiz Exp $

Merge changes from squid6 to fix build with openssl 3.

--- src/security/PeerOptions.cc.orig	2025-01-27 11:36:23.371845254 +0000
+++ src/security/PeerOptions.cc
@@ -295,130 +295,130 @@ static struct ssl_option {
 
 } ssl_options[] = {
 
-#if SSL_OP_NETSCAPE_REUSE_CIPHER_CHANGE_BUG
+#if defined(SSL_OP_NETSCAPE_REUSE_CIPHER_CHANGE_BUG)
     {
         "NETSCAPE_REUSE_CIPHER_CHANGE_BUG", SSL_OP_NETSCAPE_REUSE_CIPHER_CHANGE_BUG
     },
 #endif
-#if SSL_OP_SSLREF2_REUSE_CERT_TYPE_BUG
+#if defined(SSL_OP_SSLREF2_REUSE_CERT_TYPE_BUG)
     {
         "SSLREF2_REUSE_CERT_TYPE_BUG", SSL_OP_SSLREF2_REUSE_CERT_TYPE_BUG
     },
 #endif
-#if SSL_OP_MICROSOFT_BIG_SSLV3_BUFFER
+#if defined(SSL_OP_MICROSOFT_BIG_SSLV3_BUFFER)
     {
         "MICROSOFT_BIG_SSLV3_BUFFER", SSL_OP_MICROSOFT_BIG_SSLV3_BUFFER
     },
 #endif
-#if SSL_OP_SSLEAY_080_CLIENT_DH_BUG
+#if defined(SSL_OP_SSLEAY_080_CLIENT_DH_BUG)
     {
         "SSLEAY_080_CLIENT_DH_BUG", SSL_OP_SSLEAY_080_CLIENT_DH_BUG
     },
 #endif
-#if SSL_OP_TLS_D5_BUG
+#if defined(SSL_OP_TLS_D5_BUG)
     {
         "TLS_D5_BUG", SSL_OP_TLS_D5_BUG
     },
 #endif
-#if SSL_OP_TLS_BLOCK_PADDING_BUG
+#if defined(SSL_OP_TLS_BLOCK_PADDING_BUG)
     {
         "TLS_BLOCK_PADDING_BUG", SSL_OP_TLS_BLOCK_PADDING_BUG
     },
 #endif
-#if SSL_OP_TLS_ROLLBACK_BUG
+#if defined(SSL_OP_TLS_ROLLBACK_BUG)
     {
         "TLS_ROLLBACK_BUG", SSL_OP_TLS_ROLLBACK_BUG
     },
 #endif
-#if SSL_OP_ALL
+#if defined(SSL_OP_ALL)
     {
         "ALL", (long)SSL_OP_ALL
     },
 #endif
-#if SSL_OP_SINGLE_DH_USE
+#if defined(SSL_OP_SINGLE_DH_USE)
     {
         "SINGLE_DH_USE", SSL_OP_SINGLE_DH_USE
     },
 #endif
-#if SSL_OP_EPHEMERAL_RSA
+#if defined(SSL_OP_EPHEMERAL_RSA)
     {
         "EPHEMERAL_RSA", SSL_OP_EPHEMERAL_RSA
     },
 #endif
-#if SSL_OP_PKCS1_CHECK_1
+#if defined(SSL_OP_PKCS1_CHECK_1)
     {
         "PKCS1_CHECK_1", SSL_OP_PKCS1_CHECK_1
     },
 #endif
-#if SSL_OP_PKCS1_CHECK_2
+#if defined(SSL_OP_PKCS1_CHECK_2)
     {
         "PKCS1_CHECK_2", SSL_OP_PKCS1_CHECK_2
     },
 #endif
-#if SSL_OP_NETSCAPE_CA_DN_BUG
+#if defined(SSL_OP_NETSCAPE_CA_DN_BUG)
     {
         "NETSCAPE_CA_DN_BUG", SSL_OP_NETSCAPE_CA_DN_BUG
     },
 #endif
-#if SSL_OP_NON_EXPORT_FIRST
+#if defined(SSL_OP_NON_EXPORT_FIRST)
     {
         "NON_EXPORT_FIRST", SSL_OP_NON_EXPORT_FIRST
     },
 #endif
-#if SSL_OP_CIPHER_SERVER_PREFERENCE
+#if defined(SSL_OP_CIPHER_SERVER_PREFERENCE)
     {
         "CIPHER_SERVER_PREFERENCE", SSL_OP_CIPHER_SERVER_PREFERENCE
     },
 #endif
-#if SSL_OP_NETSCAPE_DEMO_CIPHER_CHANGE_BUG
+#if defined(SSL_OP_NETSCAPE_DEMO_CIPHER_CHANGE_BUG)
     {
         "NETSCAPE_DEMO_CIPHER_CHANGE_BUG", SSL_OP_NETSCAPE_DEMO_CIPHER_CHANGE_BUG
     },
 #endif
-#if SSL_OP_NO_SSLv3
+#if defined(SSL_OP_NO_SSLv3)
     {
         "NO_SSLv3", SSL_OP_NO_SSLv3
     },
 #endif
-#if SSL_OP_NO_TLSv1
+#if defined(SSL_OP_NO_TLSv1)
     {
         "NO_TLSv1", SSL_OP_NO_TLSv1
     },
 #else
     { "NO_TLSv1", 0 },
 #endif
-#if SSL_OP_NO_TLSv1_1
+#if defined(SSL_OP_NO_TLSv1_1)
     {
         "NO_TLSv1_1", SSL_OP_NO_TLSv1_1
     },
 #else
     { "NO_TLSv1_1", 0 },
 #endif
-#if SSL_OP_NO_TLSv1_2
+#if defined(SSL_OP_NO_TLSv1_2)
     {
         "NO_TLSv1_2", SSL_OP_NO_TLSv1_2
     },
 #else
     { "NO_TLSv1_2", 0 },
 #endif
-#if SSL_OP_NO_TLSv1_3
+#if defined(SSL_OP_NO_TLSv1_3)
     {
         "NO_TLSv1_3", SSL_OP_NO_TLSv1_3
     },
 #else
     { "NO_TLSv1_3", 0 },
 #endif
-#if SSL_OP_NO_COMPRESSION
+#if defined(SSL_OP_NO_COMPRESSION)
     {
         "No_Compression", SSL_OP_NO_COMPRESSION
     },
 #endif
-#if SSL_OP_NO_TICKET
+#if defined(SSL_OP_NO_TICKET)
     {
         "NO_TICKET", SSL_OP_NO_TICKET
     },
 #endif
-#if SSL_OP_SINGLE_ECDH_USE
+#if defined(SSL_OP_SINGLE_ECDH_USE)
     {
         "SINGLE_ECDH_USE", SSL_OP_SINGLE_ECDH_USE
     },
