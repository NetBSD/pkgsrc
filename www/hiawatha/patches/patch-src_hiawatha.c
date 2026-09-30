$NetBSD: patch-src_hiawatha.c,v 1.3 2026/09/30 20:58:57 hauke Exp $

Solarish are missing RLIMIT_NPROC

--- src/hiawatha.c.orig	2026-09-26 08:48:13.000000000 +0000
+++ src/hiawatha.c
@@ -876,10 +876,11 @@ int run_webserver(t_settings *settings) 
 			resource_limit.rlim_cur += H2_MAX_WORKERS;
 		}
 #endif
+#ifdef RLIMIT_NPROC
 		if (setrlimit(RLIMIT_NPROC, &resource_limit) != 0) {
 			fprintf(stderr, "Error setting RLIMIT_NPROC.\n");
 		}
-
+#endif /* RLIMIT_NPROC */
 		/* system: system.log, exploit.log, garbage.log, debug.log, all bindings, tomahawk connections
 		 * per child: socket, access.log, error.log, 3 CGI pipes
 		 */
