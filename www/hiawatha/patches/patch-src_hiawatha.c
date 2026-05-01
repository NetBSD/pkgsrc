$NetBSD: patch-src_hiawatha.c,v 1.2 2026/05/01 19:28:09 hauke Exp $

Solarish are missing RLIMIT_NPROC

--- src/hiawatha.c.orig	2026-04-04 17:21:19.000000000 +0000
+++ src/hiawatha.c
@@ -844,10 +844,11 @@ int run_webserver(t_settings *settings) 
 			H2_MAX_WORKERS +
 #endif
 			config->total_connections + 3;
+#ifdef RLIMIT_NPROC
 		if (setrlimit(RLIMIT_NPROC, &resource_limit) != 0) {
 			fprintf(stderr, "Error setting RLIMIT_NPROC.\n");
 		}
-
+#endif /* RLIMIT_NPROC */
 		/* system: system.log, exploit.log, garbage.log, debug.log, all bindings, tomahawk connections
 		 * per child: socket, access.log, error.log, 3 CGI pipes
 		 */
