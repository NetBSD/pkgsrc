$NetBSD: patch-utils_xtgettcap.c,v 1.1 2026/04/14 12:11:49 kikadf Exp $

* Fix ctype usage

--- utils/xtgettcap.c.orig	2026-02-06 09:32:13.200532969 +0000
+++ utils/xtgettcap.c
@@ -100,7 +100,7 @@ main(int argc, const char *const *argv)
         printf("reply: (%zd chars): ", count);
 
         for (size_t i = 0; i < (size_t)count; i++) {
-            if (isprint(buf[i]))
+            if (isprint((unsigned char)buf[i]))
                 printf("%c", buf[i]);
             else if (buf[i] == '\033')
                 printf("\033[1;31m<ESC>\033[m");
@@ -161,7 +161,7 @@ main(int argc, const char *const *argv)
 
                 printf("  \033[%dm", color);
                 for (size_t i = 0 ; i < len; i++) {
-                    if (isprint(decoded[i])) {
+                    if (isprint((unsigned char)decoded[i])) {
                         /* All printable characters */
                         printf("%c", decoded[i]);
                     }
