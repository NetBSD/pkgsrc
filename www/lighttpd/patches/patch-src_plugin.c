$NetBSD: patch-src_plugin.c,v 1.1 2013/01/11 11:00:02 fhajny Exp $

On SunOS, dlopen() may return non-NULL on success too.
--- src/plugin.c.orig	2010-08-17 09:04:38.000000000 +0000
+++ src/plugin.c
@@ -205,12 +205,14 @@ int plugins_load(server *srv) {
 #else
 		*(void **)(&init) = dlsym(p->lib, srv->tmp_buf->ptr);
 #endif
+#if !defined(__sun)
 		if ((error = dlerror()) != NULL)  {
 			log_error_write(srv, __FILE__, __LINE__, "s", error);
 
 			plugin_free(p);
 			return -1;
 		}
+#endif
 
 #endif
 		if ((*init)(p)) {
