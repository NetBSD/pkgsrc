$NetBSD: patch-plugins_gccgo_gccgo__plugin.c,v 1.1 2016/01/11 22:57:00 joerg Exp $

--- plugins/gccgo/gccgo_plugin.c.orig	2016-01-11 16:11:52.000000000 +0000
+++ plugins/gccgo/gccgo_plugin.c
@@ -233,9 +233,8 @@ static int uwsgi_gccgo_request(struct ws
 
 	wsgi_req->async_environ = uwsgigo_env(wsgi_req);
 	int i;
-        for(i=0;i<wsgi_req->var_cnt;i++) {
+        for(i=0;i<wsgi_req->var_cnt;i+=2) {
                 uwsgigo_env_add(wsgi_req->async_environ, wsgi_req->hvec[i].iov_base,  wsgi_req->hvec[i].iov_len, wsgi_req->hvec[i+1].iov_base, wsgi_req->hvec[i+1].iov_len);
-                i++;
         }
 	uwsgigo_request(wsgi_req->async_environ, wsgi_req);
 end:
