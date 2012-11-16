$NetBSD: patch-lib_libxview_server_svr__parse.c,v 1.1 2012/11/16 00:29:40 joerg Exp $

--- lib/libxview/server/svr_parse.c.orig	2012-11-14 15:26:31.000000000 +0000
+++ lib/libxview/server/svr_parse.c
@@ -674,7 +674,7 @@ CHAR			*pos;
     /* if keysym already set, that's an error */
     if( avp->keysym ) {
 	avp->error = 1;
-	return;
+	return NULL;
     }
 
     /* look for 'raw' space or punctuation */
