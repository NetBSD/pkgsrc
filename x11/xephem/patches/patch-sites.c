$NetBSD: patch-sites.c,v 1.1 2026/06/27 20:07:53 gdt Exp $

Fix ctype(3) UB.   Taken from https://github.com/XEphem/XEphem/pull/126

--- sites.c.orig	2024-02-13 14:35:36.000000000 +0000
+++ sites.c
@@ -183,9 +183,9 @@ int maxn;
 	 * n is an index, not a count.
 	 */
 	for (n = fl-1; n >= maxn-4; ) {
-	    while (n > 0 && isalnum(full[n]))
+	    while (n > 0 && isalnum((unsigned char)full[n]))
 		n--;
-	    while (n > 0 && (ispunct(full[n]) || isspace(full[n])))
+	    while (n > 0 && (ispunct((unsigned char)full[n]) || isspace((unsigned char)full[n])))
 		n--;
 	}
 	(void) sprintf (ab, "%.*s...", n+1, full);
@@ -654,7 +654,7 @@ read_file (FILE *fp)
 
 	    /* strip trailing blanks off name */
 	    for (l = strlen (name); --l >= 0; )
-		if (isspace(name[l]))
+		if (isspace((unsigned char)name[l]))
 		    name[l] = '\0';
 		else
 		    break;
