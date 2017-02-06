$NetBSD: patch-src_squidclamav.h,v 1.1 2017/02/06 15:37:41 adam Exp $

Remove unused but conflicting strlcat() definition.

--- src/squidclamav.h.orig	2017-02-06 15:28:58.000000000 +0000
+++ src/squidclamav.h
@@ -30,7 +30,6 @@ void chomp(char *);
 int isPathExists(const char *);
 int isFileExists(const char *);
 int isPathSecure(const char *);
-size_t strlcat(char *dst, const char *src, size_t siz);
 size_t xstrnlen(const char *s, size_t n);
 char** split( char* str, const char* delim);
 
