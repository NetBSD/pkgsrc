$NetBSD: patch-Key.c,v 1.1 2022/01/14 02:00:00 gutteridge Exp $

Fix builds where getentropy() exists but arc4random_buf() does not, as
reported to be the case with Solaris 11.3 in PR pkg/54628.

--- Key.c.orig	2019-03-16 16:21:22.000000000 +0000
+++ Key.c
@@ -64,6 +64,10 @@ getbits (long data, unsigned char *dst)
 
 #ifndef HAVE_ARC4RANDOM_BUF
 
+#ifdef HAVE_GETENTROPY
+#include <sys/random.h>
+#endif
+
 static void
 insecure_getrandom_buf (unsigned char *auth, int len)
 {
