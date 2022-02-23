$NetBSD: patch-Key.c,v 1.3 2022/02/23 03:10:26 gutteridge Exp $

Fix builds where getentropy() exists but arc4random_buf() does not, as
reported to be the case with Solaris 11.3 in PR pkg/54628.

--- Key.c.orig	2019-03-16 16:21:22.000000000 +0000
+++ Key.c
@@ -82,6 +82,11 @@ arc4random_buf (void *auth, int len)
     int	    ret;
 
 #if HAVE_GETENTROPY
+
+#ifdef __sun
+#include <sys/random.h>
+#endif
+
     /* weak emulation of arc4random through the getentropy libc call */
     ret = getentropy (auth, len);
     if (ret == 0)
