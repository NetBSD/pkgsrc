$NetBSD: patch-lib_setproctitle.c,v 1.2 2017/11/23 20:27:20 wiz Exp $

Remove setproctitle, conflicts with NetBSD version and not used
in mcookie.

--- lib/setproctitle.c.orig	2017-09-27 09:05:13.698361518 +0000
+++ lib/setproctitle.c
@@ -49,27 +49,3 @@ void initproctitle (int argc, char **arg
 	if (argv_lth > 1)
 		argv0 = argv;
 }
-
-void setproctitle (const char *prog, const char *txt)
-{
-        size_t i;
-        char buf[SPT_BUFSIZE];
-
-        if (!argv0)
-                return;
-
-	if (strlen(prog) + strlen(txt) + 5 > SPT_BUFSIZE)
-		return;
-
-	sprintf(buf, "%s -- %s", prog, txt);
-
-        i = strlen(buf);
-        if (i > argv_lth - 2) {
-                i = argv_lth - 2;
-                buf[i] = '\0';
-        }
-	memset(argv0[0], '\0', argv_lth);       /* clear the memory area */
-        strcpy(argv0[0], buf);
-
-        argv0[1] = NULL;
-}
