$NetBSD: patch-GUI_xephem_tools_xedb_xedb.c,v 1.1 2026/06/28 00:44:25 gdt Exp $

--- GUI/xephem/tools/xedb/xedb.c.orig	2024-02-13 14:35:36.000000000 +0000
+++ GUI/xephem/tools/xedb/xedb.c
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
