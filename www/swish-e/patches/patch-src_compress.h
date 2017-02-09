$NetBSD: patch-src_compress.h,v 1.1 2017/02/09 00:18:01 joerg Exp $

--- src/compress.h.orig	2017-02-08 21:48:02.207439712 +0000
+++ src/compress.h
@@ -36,7 +36,7 @@ void compress1(int num, FILE *fp, int (*
 unsigned char *compress3(int num, unsigned char *buffer);
 
 int uncompress1(FILE *fp, int (*f_getc)(FILE *fp));
-int uncompress2(unsigned char **buffer);
+int swish_uncompress2(unsigned char **buffer);
 
 
 unsigned long PACKLONG(unsigned long num);
