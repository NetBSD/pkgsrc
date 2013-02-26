$NetBSD: patch-clients_xmxinit_xmxinit.c,v 1.1 2013/02/26 10:18:42 joerg Exp $

--- clients/xmxinit/xmxinit.c.orig	2013-02-25 14:22:16.000000000 +0000
+++ clients/xmxinit/xmxinit.c
@@ -146,8 +146,7 @@ sigUsr1(sig)
 #endif
 }
 
-static Execute (vec)
-    char **vec;				/* has room from up above */
+static void Execute (char **vec)
 {
     execvp (vec[0], vec);
     if (access (vec[0], R_OK) == 0) {
