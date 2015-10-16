$NetBSD: patch-bozohttpd.c,v 1.1 2015/10/16 20:09:02 richard Exp $

SunOS doesn't define d_namlen element of dirent structure
but uses d_reclen instead, so define an alias.

--- bozohttpd.c.orig	2015-03-25 23:38:50.000000000 +0000
+++ bozohttpd.c
@@ -1093,6 +1093,9 @@ check_virtual(bozo_httpreq_t *request)
 				}
 				debug((httpd, DEBUG_OBESE, "looking at dir``%s''",
 			 	   d->d_name));
+#ifdef __sun
+#define d_namlen d_reclen
+#endif
 				if (d->d_namlen == len && strcmp(d->d_name,
 				    request->hr_host) == 0) {
 					/* found it, punch it */
