$NetBSD: patch-src_download.c,v 1.4 2015/02/04 20:02:04 khorben Exp $

--- src/download.c.orig	2014-12-24 17:59:14.000000000 +0000
+++ src/download.c
@@ -35,6 +35,7 @@
 #endif
 #include <System.h>
 #ifdef WITH_WEBKIT
+# include <netdb.h>
 # include <arpa/inet.h>
 # include <webkit/webkit.h>
 #else
