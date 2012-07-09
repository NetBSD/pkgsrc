$NetBSD: patch-HiRes.xs,v 1.2 2012/07/09 06:33:35 wiz Exp $

Fix off-by-one. From Michai Ramakers in PR 46673.
https://rt.cpan.org/Public/Bug/Display.html?id=78266

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
