$NetBSD: patch-plugins_cgi_cgi__plugin.c,v 1.1 2016/01/11 22:57:00 joerg Exp $

--- plugins/cgi/cgi_plugin.c.orig	2016-01-11 16:11:06.000000000 +0000
+++ plugins/cgi/cgi_plugin.c
@@ -763,12 +763,11 @@ clear2:
 	}
 
 	// fill cgi env
-	for(i=0;i<wsgi_req->var_cnt;i++) {
+	for(i=0;i<wsgi_req->var_cnt;i+=2) {
 		// no need to free the putenv() memory
 		if (putenv(uwsgi_concat3n(wsgi_req->hvec[i].iov_base, wsgi_req->hvec[i].iov_len, "=", 1, wsgi_req->hvec[i+1].iov_base, wsgi_req->hvec[i+1].iov_len))) {
 			uwsgi_error("putenv()");
 		}
-		i++;
 	}
 
 
