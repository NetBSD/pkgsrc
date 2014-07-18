$NetBSD: patch-src_generic.c,v 1.1 2014/07/18 10:21:36 ryoon Exp $

--- src/generic.c.orig	2004-08-31 19:07:23.000000000 +0000
+++ src/generic.c
@@ -101,7 +101,12 @@ generic_create(const char *catname, bool
     } else {
         FILE *f;
 
+/* SCO OpenServer 5.0.7/3.2's fdopen does not accept "a" in this case. */
+#if defined(_SCO_DS)
+        f = fdopen(fd, "w");
+#else
         f = fdopen(fd, "a");
+#endif
         if (f == NULL) {
             warn("failed to create `%s'", catname);
             close(fd);
