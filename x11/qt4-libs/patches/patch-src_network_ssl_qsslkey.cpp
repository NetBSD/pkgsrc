$NetBSD: patch-src_network_ssl_qsslkey.cpp,v 1.1 2018/01/17 18:37:34 markd Exp $

Compile with openssl-1.1.0 http://bugs.debian.org/828522 via archlinux

--- src/network/ssl/qsslkey.cpp.orig	2015-05-07 14:14:44.000000000 +0000
+++ src/network/ssl/qsslkey.cpp
@@ -321,8 +321,19 @@ int QSslKey::length() const
 {
     if (d->isNull)
         return -1;
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
     return (d->algorithm == QSsl::Rsa)
            ? q_BN_num_bits(d->rsa->n) : q_BN_num_bits(d->dsa->p);
+#else
+    if (d->algorithm == QSsl::Rsa) {
+        return q_RSA_bits(d->rsa);
+    }else{
+        const BIGNUM *p = NULL;
+        q_DSA_get0_pqg(d->dsa, &p, NULL, NULL);
+	return q_BN_num_bits(p);
+    }
+#endif
+
 }
 
 /*!
