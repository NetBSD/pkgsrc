$NetBSD: patch-src_finders.c,v 1.1 2025/10/29 23:50:00 gutteridge Exp $

Use ctype.h correctly.

--- src/finders.c.orig	2025-06-23 13:11:03.000000000 +0000
+++ src/finders.c
@@ -114,7 +114,7 @@ EwinsFindByExpr(const char *match, int *
         goto do_one;
     }
 
-    if (isdigit(match[0]))
+    if (isdigit((unsigned char)match[0]))
     {
         unsigned int    win;
 
