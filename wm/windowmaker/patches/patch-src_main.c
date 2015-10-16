$NetBSD: patch-src_main.c,v 1.1 2015/10/16 10:42:23 adam Exp $

--- src/main.c.orig	2015-08-11 18:41:14.000000000 +0000
+++ src/main.c
@@ -31,6 +31,7 @@
 #include <sys/stat.h>
 #include <sys/types.h>
 #include <fcntl.h>
+#include <signal.h>
 
 #include <X11/Xlib.h>
 #include <X11/Xutil.h>
@@ -241,6 +242,12 @@ void SetupEnvironment(WScreen * scr)
 {
 	char *tmp, *ptr;
 	char buf[16];
+	struct sigaction sa;
+
+	sa.sa_handler = SIG_DFL;
+	sigemptyset(&sa.sa_mask);
+	/* sa.sa_mask = 0; */
+	sigaction(SIGPIPE, &sa, NULL);
 
 	if (multiHead) {
 		int len = strlen(DisplayName) + 64;
