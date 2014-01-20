$NetBSD: patch-src_download.c,v 1.1 2014/01/20 18:21:29 khorben Exp $

Added missing include for download(1) with WebKit (as by default)

--- src/download.c.orig	2012-10-06 01:34:55.000000000 +0000
+++ src/download.c
@@ -32,6 +32,7 @@
 #include <gtk/gtk.h>
 #include <System.h>
 #ifdef WITH_WEBKIT
+# include <arpa/inet.h>
 # include <webkit/webkit.h>
 #else
 # define GNET_EXPERIMENTAL
