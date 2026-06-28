$NetBSD: patch-libastro_constel.c,v 1.1 2026/06/28 00:51:59 gdt Exp $

Fix ctype(3) UB.  Cherry-picked from https://github.com/XEphem/XEphem/pull/126

--- libastro/constel.c.orig	2024-02-13 14:35:36.000000000 +0000
+++ libastro/constel.c
@@ -1665,9 +1665,9 @@ cns_loadfigs (FILE *fp, char *msg)
 	    int code;
 
 	    /* skip leading/trailing whitespace, blank lines and # lines */
-	    for (lp = line+strlen(line)-1; lp>=line && isspace(*lp); --lp)
+	    for (lp = line+strlen(line)-1; lp>=line && isspace((unsigned char)*lp); --lp)
 		*lp = '\0';
-	    for (lp = line; isspace(*lp); lp++)
+	    for (lp = line; isspace((unsigned char)*lp); lp++)
 		continue;
 	    if (*lp == '#' || *lp == '\0')
 		continue;
