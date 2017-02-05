$NetBSD: patch-bozohttpd.c,v 1.4 2017/02/05 13:32:16 leot Exp $

Adjust SERVER_SOFTWARE to intended version.

From -r1.86 of NetBSD's src/libexec/httpd/bozohttpd.c

--- bozohttpd.c.orig	2017-02-01 04:21:23.000000000 +0000
+++ bozohttpd.c
@@ -109,7 +109,7 @@
 #define INDEX_HTML		"index.html"
 #endif
 #ifndef SERVER_SOFTWARE
-#define SERVER_SOFTWARE		"bozohttpd/20170102"
+#define SERVER_SOFTWARE		"bozohttpd/20170201"
 #endif
 #ifndef DIRECT_ACCESS_FILE
 #define DIRECT_ACCESS_FILE	".bzdirect"
