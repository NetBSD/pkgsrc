$NetBSD: patch-src_cli.c,v 1.2 2020/09/01 19:25:00 fcambus Exp $

--- src/cli.c.orig	2020-08-26 07:20:35.000000000 +0000
+++ src/cli.c
@@ -1120,7 +1120,7 @@ cli_build_asset(char *fpath, struct dire
 
 	/* Replace dots, spaces, etc etc with underscores. */
 	for (p = name; *p != '\0'; p++) {
-		if (*p == '.' || isspace(*p) || *p == '-')
+		if (*p == '.' || isspace((unsigned char)*p) || *p == '-')
 			*p = '_';
 	}
 
