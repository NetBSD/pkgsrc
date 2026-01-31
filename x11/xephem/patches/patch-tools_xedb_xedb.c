$NetBSD: patch-tools_xedb_xedb.c,v 1.1 2026/01/31 18:05:27 gdt Exp $

While xedb doesn't seem to be used, patch wrong hardcoded path to app
defaults, in conjuction with a SUBST.

Not reported upstream until there is more clarity about this change,
and also about future maintenance.

--- tools/xedb/xedb.c.orig	2024-02-13 14:35:36.000000000 +0000
+++ tools/xedb/xedb.c
@@ -188,13 +188,8 @@ findResFile (char path[])
 	    return (found);
 	}
 
-	/* try some common system places */
-	sprintf (path, "/usr/X11R6/lib/X11/app-defaults/XEphem");
-	if ((fp = fopen (path, "r")) != NULL) {
-	    fclose (fp);
-	    return (0);
-	}
-	sprintf (path, "/usr/lib/X11/app-defaults/XEphem");
+	/* Use pkgsrc's configured prefix, only. */
+	sprintf (path, "@PREFIX@/lib/X11/app-defaults/XEphem");
 	if ((fp = fopen (path, "r")) != NULL) {
 	    fclose (fp);
 	    return (0);
