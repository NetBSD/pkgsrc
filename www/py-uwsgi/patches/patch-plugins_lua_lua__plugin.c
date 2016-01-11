$NetBSD: patch-plugins_lua_lua__plugin.c,v 1.1 2016/01/11 22:57:00 joerg Exp $

--- plugins/lua/lua_plugin.c.orig	2016-01-11 16:11:52.000000000 +0000
+++ plugins/lua/lua_plugin.c
@@ -764,13 +764,12 @@ static int uwsgi_lua_request(struct wsgi
 	lua_newtable(L);
 	lua_pushstring(L, "");
 	lua_setfield(L, -2, "CONTENT_TYPE");
-	for(i=0;i<wsgi_req->var_cnt;i++) {
+	for(i=0;i<wsgi_req->var_cnt;i+=2) {
 		lua_pushlstring(L, (char *)wsgi_req->hvec[i+1].iov_base, wsgi_req->hvec[i+1].iov_len);
 		// transform it in a valid c string TODO this is ugly
 		ptrbuf = wsgi_req->hvec[i].iov_base+wsgi_req->hvec[i].iov_len;
 		*ptrbuf = 0;
 		lua_setfield(L, -2, (char *)wsgi_req->hvec[i].iov_base);
-		i++;
 	}
 
 
