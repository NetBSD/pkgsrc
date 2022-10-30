$NetBSD: patch-src_util.c,v 1.1 2022/10/30 21:58:30 wiedi Exp $

No tm_gmtoff on SunOS

--- src/util.c.orig	2022-09-29 15:15:53.000000000 +0000
+++ src/util.c
@@ -568,7 +568,11 @@ tm2time (const struct tm *src) {
   struct tm tmp;
 
   tmp = *src;
+#if defined(__sun)
+  return timegm (&tmp);
+#else
   return timegm (&tmp) - src->tm_gmtoff;
+#endif
 }
 
 void
