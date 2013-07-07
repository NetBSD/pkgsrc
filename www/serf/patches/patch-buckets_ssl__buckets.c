$NetBSD: patch-buckets_ssl__buckets.c,v 1.1 2013/07/07 01:18:46 obache Exp $

* for old OpenSSL, lack of SSL_clear_options.

--- buckets/ssl_buckets.c.orig	2013-06-03 17:06:45.000000000 +0000
+++ buckets/ssl_buckets.c
@@ -64,6 +64,10 @@
 #define APR_ARRAY_PUSH(ary,type) (*((type *)apr_array_push(ary)))
 #endif
 
+#if defined(SSL_OP_NO_COMPRESSION) && !defined(SSL_clear_options)
+#define SSL_clear_options(ssl, op) \
+    SSL_set_options((ssl), SSL_get_options((ssl)) & ~(op))
+#endif
 
 /*
  * Here's an overview of the SSL bucket's relationship to OpenSSL and serf.
