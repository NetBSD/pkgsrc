$NetBSD: patch-kio_kssl_ksslutils.cpp,v 1.1 2018/01/17 18:53:25 markd Exp $

Support openssl-1.1 

--- kio/kssl/ksslutils.cpp.orig	2016-12-08 18:44:10.000000000 +0000
+++ kio/kssl/ksslutils.cpp
@@ -84,7 +84,7 @@ QString ASN1_UTCTIME_QString(ASN1_UTCTIM
 QString ASN1_INTEGER_QString(ASN1_INTEGER *aint) {
 char *rep = KOSSL::self()->i2s_ASN1_INTEGER(NULL, aint);
 QString yy = rep;
-KOSSL::self()->OPENSSL_free(rep);
+::OPENSSL_free(rep);
 return yy;
 }
 
