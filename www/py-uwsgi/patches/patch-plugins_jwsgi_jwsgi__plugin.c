$NetBSD: patch-plugins_jwsgi_jwsgi__plugin.c,v 1.1 2016/01/11 22:57:00 joerg Exp $

--- plugins/jwsgi/jwsgi_plugin.c.orig	2016-01-11 16:11:52.000000000 +0000
+++ plugins/jwsgi/jwsgi_plugin.c
@@ -71,13 +71,12 @@ static int uwsgi_jwsgi_request(struct ws
 	if (!hm) return -1;
 
 	int i;
-	for(i=0;i<wsgi_req->var_cnt;i++) {
+	for(i=0;i<wsgi_req->var_cnt;i+=) {
                 char *hk = wsgi_req->hvec[i].iov_base;
                 uint16_t hk_l = wsgi_req->hvec[i].iov_len;
                 char *hv = wsgi_req->hvec[i+1].iov_base;
                 uint16_t hv_l = wsgi_req->hvec[i+1].iov_len;
 		if (uwsgi_jwsgi_add_request_item(hm, hk, hk_l, hv, hv_l)) goto end;
-		i++;
 	}
 
 	if (uwsgi_jwsgi_add_request_input(hm, "jwsgi.input", 11)) goto end;
