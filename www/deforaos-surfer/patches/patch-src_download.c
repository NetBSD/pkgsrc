$NetBSD: patch-src_download.c,v 1.2 2014/02/14 13:29:23 joerg Exp $

Added missing include for download(1) with WebKit (as by default)

--- src/download.c.orig	2012-10-06 01:34:55.000000000 +0000
+++ src/download.c
@@ -31,7 +31,9 @@
 #include <libintl.h>
 #include <gtk/gtk.h>
 #include <System.h>
+#include <netdb.h>
 #ifdef WITH_WEBKIT
+# include <arpa/inet.h>
 # include <webkit/webkit.h>
 #else
 # define GNET_EXPERIMENTAL
