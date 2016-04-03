$NetBSD: patch-src_Server_IO__buffer.c,v 1.1 2016/04/03 20:24:27 joerg Exp $

--- src/Server/IO_buffer.c.orig	2016-04-03 16:02:03.907973300 +0000
+++ src/Server/IO_buffer.c
@@ -7,6 +7,8 @@
 #define NEWBUFFER 1
 #define BLOCKING 1
 
+bool screws_send(int s,int b, char *i);
+
 void
 IO_buffer(n,s,out)
 	int n;
