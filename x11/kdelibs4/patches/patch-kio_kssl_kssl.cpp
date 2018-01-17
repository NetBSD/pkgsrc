$NetBSD: patch-kio_kssl_kssl.cpp,v 1.1 2018/01/17 18:53:25 markd Exp $

Support openssl-1.1 

--- kio/kssl/kssl.cpp.orig	2016-12-08 18:44:10.000000000 +0000
+++ kio/kssl/kssl.cpp
@@ -70,7 +70,7 @@ public:
 #ifdef KSSL_HAVE_SSL
 	SSL *m_ssl;
 	SSL_CTX *m_ctx;
-	SSL_METHOD *m_meth;
+	const SSL_METHOD *m_meth;
 #endif
 	KOSSL *kossl;
 };
