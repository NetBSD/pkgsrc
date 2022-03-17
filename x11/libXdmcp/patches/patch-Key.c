$NetBSD: patch-Key.c,v 1.4 2022/03/17 01:05:48 gutteridge Exp $

Fix builds where getentropy() exists but arc4random_buf() does not, as
the case with Solaris 11.3, reported in PR pkg/54628.
https://gitlab.freedesktop.org/xorg/lib/libxdmcp/-/commit/4a71fdf6d34df67d3f1335590da6ae3050128fb2

--- Key.c.orig	2019-03-16 16:21:22.000000000 +0000
+++ Key.c
@@ -64,6 +64,11 @@ getbits (long data, unsigned char *dst)
 
 #ifndef HAVE_ARC4RANDOM_BUF
 
+/* Solaris 11.3.0 - 11.4.15 only define getentropy() in <sys/random.h> */
+#if HAVE_GETENTROPY && HAVE_SYS_RANDOM_H
+# include <sys/random.h>
+#endif
+
 static void
 insecure_getrandom_buf (unsigned char *auth, int len)
 {
