$NetBSD: patch-progman.c,v 1.1 2022/04/17 21:16:12 sjmulder Exp $

Replace use of pipe2() for macOS compatibility.

--- progman.c.orig	2022-04-17 21:02:47.000000000 +0000
+++ progman.c
@@ -186,8 +186,11 @@ main(int argc, char **argv)
 
 	read_config();
 
-	if (pipe2(exitmsg, O_CLOEXEC) != 0)
-		err(1, "pipe2");
+	if (pipe(exitmsg) != 0)
+		err(1, "pipe");
+	if (fcntl(exitmsg[0], F_SETFD, FD_CLOEXEC) != 0 ||
+	    fcntl(exitmsg[1], F_SETFD, FD_CLOEXEC) != 0)
+		err(1, "fcntl");
 
 	act.sa_handler = sig_handler;
 	act.sa_flags = 0;
