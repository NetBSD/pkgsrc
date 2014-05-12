$NetBSD: patch-pkg.sslmod_ssl__util__ssl.c,v 1.1 2014/05/12 10:37:25 jperkin Exp $

Catch up with newer OpenSSL API.

--- pkg.sslmod/ssl_util_ssl.c.orig	2006-05-08 07:15:38.000000000 +0000
+++ pkg.sslmod/ssl_util_ssl.c
@@ -324,7 +324,7 @@ BOOL SSL_X509_isSGC(X509 *cert)
 {
     X509_EXTENSION *ext;
     int ext_nid;
-    STACK *sk;
+    _STACK *sk;
     BOOL is_sgc;
     int idx;
     int i;
@@ -333,7 +333,7 @@ BOOL SSL_X509_isSGC(X509 *cert)
     idx = X509_get_ext_by_NID(cert, NID_ext_key_usage, -1);
     if (idx >= 0) {
         ext = X509_get_ext(cert, idx);
-        if ((sk = (STACK *)X509V3_EXT_d2i(ext)) != NULL) {
+        if ((sk = (_STACK *)X509V3_EXT_d2i(ext)) != NULL) {
             for (i = 0; i < sk_num(sk); i++) {
                 ext_nid = OBJ_obj2nid((ASN1_OBJECT *)sk_value(sk, i));
                 if (ext_nid == NID_ms_sgc || ext_nid == NID_ns_sgc) {
