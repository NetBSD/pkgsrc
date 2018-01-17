$NetBSD: patch-kio_kssl_ksslcertchain.cpp,v 1.1 2018/01/17 18:53:25 markd Exp $

Support openssl-1.1 

--- kio/kssl/ksslcertchain.cpp.orig	2016-12-08 18:44:10.000000000 +0000
+++ kio/kssl/ksslcertchain.cpp
@@ -44,16 +44,6 @@
 #include <kdebug.h>
 #include <QtCore/QStringList>
 
-#ifdef KSSL_HAVE_SSL
-#define sk_new d->kossl->sk_new
-#define sk_push d->kossl->sk_push
-#define sk_free d->kossl->sk_free
-#define sk_value d->kossl->sk_value
-#define sk_num d->kossl->sk_num
-#define sk_dup d->kossl->sk_dup
-#define sk_pop d->kossl->sk_pop
-#endif
-
 class KSSLCertChainPrivate {
 public:
   KSSLCertChainPrivate() {
