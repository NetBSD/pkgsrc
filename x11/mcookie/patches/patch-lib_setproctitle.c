$NetBSD: patch-lib_setproctitle.c,v 1.1 2016/09/20 08:00:51 wiz Exp $

Remove setproctitle, conflicts with NetBSD version and not used
in mcookie.

--- lib/setproctitle.c.orig	2016-03-08 12:00:42.000000000 +0000
+++ lib/setproctitle.c
@@ -48,27 +48,3 @@ void initproctitle (int argc, char **arg
 	else
 		argv_lth = argv0[argc-1] + strlen(argv0[argc-1]) - argv0[0];
 }
-
-void setproctitle (const char *prog, const char *txt)
-{
-        int i;
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
