$NetBSD: patch-src_cli.c,v 1.1 2020/01/12 23:01:06 joerg Exp $

--- src/cli.c.orig	2020-01-11 18:45:39.562950385 +0000
+++ src/cli.c
@@ -985,7 +985,7 @@ cli_build_asset(char *fpath, struct dire
 
 	/* Replace dots, spaces, etc etc with underscores. */
 	for (p = name; *p != '\0'; p++) {
-		if (*p == '.' || isspace(*p) || *p == '-')
+		if (*p == '.' || isspace((unsigned char)*p) || *p == '-')
 			*p = '_';
 	}
 
