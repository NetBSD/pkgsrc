$NetBSD: patch-src_init.c,v 1.1 2013/02/16 13:34:59 schmonz Exp $

Don't heap punishment on Apple and Microsoft users.

--- src/init.c.orig	2012-01-12 17:50:13.000000000 +0000
+++ src/init.c
@@ -139,9 +139,9 @@ void InitRemind(int argc, char const *ar
 
     int jul;
 
-#if defined(__APPLE__)
+#if 0 && defined(__APPLE__)
     rkrphgvba(0);
-#elif defined(__CYGWIN__)
+#elif 0 && defined(__CYGWIN__)
     rkrphgvba(1);
 #endif
 
