$NetBSD: patch-xidle.c,v 1.1 2022/10/08 10:06:52 bsiegert Exp $

Portability fixes:

- Define non-standard compiler attribute extension.
- Do not hard-code xlock path.
- Disable pledge.
- Use libbsd on Linux.

--- xidle.c.orig	2022-07-18 06:17:31.000000000 +0000
+++ xidle.c
@@ -39,15 +39,21 @@
 #include <stdlib.h>
 #include <string.h>
 #include <unistd.h>
+#ifdef __linux__
+#include <bsd/stdlib.h>
+#endif
 
 #ifndef CLASS_NAME
 #define CLASS_NAME	"XIdle"
 #endif
 
 #ifndef PATH_PROG
-#define PATH_PROG	"/usr/X11R6/bin/xlock"
+#define PATH_PROG	"@PREFIX@/bin/xlock"
 #endif
 
+#ifndef	__dead 
+#define __dead      __attribute__((__noreturn__))
+#endif
 
 enum {
 	north = 0x01,
@@ -354,9 +360,6 @@ main(int argc, char **argv)
 	if (fd > 2)
 		close(fd);
 
-	if (pledge("stdio proc exec", NULL) == -1)
-		err(1, "pledge");
-
 	for (;;) {
 		XEvent ev;
 		u_long mask;
