$NetBSD: patch-src_base.h,v 1.1 2018/11/01 09:25:29 bsiegert Exp $

--- src/base.h.orig	2017-07-30 08:53:35.000000000 +0000
+++ src/base.h
@@ -2,6 +2,7 @@
 #define __BASE_H
 
 #include <stddef.h>
+#include <string.h>
 
 #ifndef __GNUC__
 #define __attribute__(a)
@@ -43,11 +44,6 @@ inline T abs(T v) {
 
 /*** String Functions *********************************************************/
 
-/* Prefer this as a safer alternative over strcpy. Return strlen(from). */
-size_t strlcpy(char *dest, const char *from, size_t dest_size);
-/* Prefer this over strcat. Return strlen(dest) + strlen(from). */
-size_t strlcat(char *dest, const char *from, size_t dest_size);
-
 char *newstr(char const *str);
 char *newstr(char const *str, int len);
 char *newstr(char const *str, char const *delim);
