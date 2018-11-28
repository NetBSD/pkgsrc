$NetBSD: patch-fcgiwrap.c,v 1.1 2018/11/28 16:06:36 jperkin Exp $

Appease -Werror=implicit-fallthrough.

--- fcgiwrap.c.orig	2013-02-03 13:25:17.000000000 +0000
+++ fcgiwrap.c
@@ -553,7 +553,7 @@ static void handle_fcgi_request(void)
 
 			execl(filename, filename, (void *)NULL);
 			cgi_error("502 Bad Gateway", "Cannot execute script", filename);
-
+			break;
 		default: /* parent */
 			close(pipe_in[0]);
 			close(pipe_out[1]);
