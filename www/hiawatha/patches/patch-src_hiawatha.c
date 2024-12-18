$NetBSD: patch-src_hiawatha.c,v 1.1 2024/12/18 16:44:36 hauke Exp $

Solarish are missing RLIMIT_NPROC

--- src/hiawatha.c.orig	2024-12-18 16:38:01.001436946 +0000
+++ src/hiawatha.c
@@ -791,10 +791,11 @@ int run_webserver(t_settings *settings) 
 	 */
 	if (config->set_rlimits) {
 		resource_limit.rlim_max = resource_limit.rlim_cur = config->total_connections + 3;
+#ifdef RLIMIT_NPROC
 		if (setrlimit(RLIMIT_NPROC, &resource_limit) != 0) {
 			fprintf(stderr, "Error setting RLIMIT_NPROC.\n");
 		}
-
+#endif /* RLIMIT_NPROC */
 		/* system: system.log, exploit.log, garbage.log, debug.log, all bindings, tomahawk connections
 		 * per child: socket, access.log, error.log, 3 CGI pipes
 		 */
