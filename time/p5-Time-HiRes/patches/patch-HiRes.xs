$NetBSD: patch-HiRes.xs,v 1.1 2012/07/08 21:23:08 wiz Exp $

Fix off-by-one. From Michai Ramakers in PR 46673.

--- HiRes.xs.orig	2011-06-08 18:36:38.000000000 +0000
+++ HiRes.xs
@@ -792,7 +792,7 @@ usleep(useconds)
 	CODE:
 	gettimeofday(&Ta, NULL);
 	if (items > 0) {
-	    if (useconds > 1E6) {
+	    if (useconds >= 1E6) {
 		IV seconds = (IV) (useconds / 1E6);
 		/* If usleep() has been implemented using setitimer()
 		 * then this contortion is unnecessary-- but usleep()
