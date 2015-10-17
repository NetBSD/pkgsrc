$NetBSD: patch-bozohttpd.c,v 1.2 2015/10/17 06:06:49 richard Exp $

SunOS doesn't define d_namlen element of dirent structure
only d_reclen, so use strlen to determine d_namlen.

--- bozohttpd.c.orig	2015-03-25 23:38:50.000000000 +0000
+++ bozohttpd.c
@@ -1093,7 +1093,11 @@ check_virtual(bozo_httpreq_t *request)
 				}
 				debug((httpd, DEBUG_OBESE, "looking at dir``%s''",
 			 	   d->d_name));
+#ifndef __sun
 				if (d->d_namlen == len && strcmp(d->d_name,
+#else
+				if (strlen(d->d_name) == len && strcmp(d->d_name,
+#endif
 				    request->hr_host) == 0) {
 					/* found it, punch it */
 					debug((httpd, DEBUG_OBESE, "found it punch it"));
