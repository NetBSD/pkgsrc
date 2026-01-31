$NetBSD: patch-homeio.c,v 1.1 2026/01/31 18:10:10 gdt Exp $

In part, patch path to app-defaults.

Not submitted upstream until a) better understood and b) upstream
maintenance status is clearer.

--- homeio.c.orig	2024-02-13 14:35:36.000000000 +0000
+++ homeio.c
@@ -11,6 +11,9 @@
 #include <time.h>
 #include <sys/types.h>
 #include <sys/stat.h>
+#if defined(__STDC__)
+#include <errno.h>
+#endif
 
 #include "xephem.h"
 
@@ -192,31 +195,11 @@ tempfilename (char *buf, char *name, cha
 char *
 getShareDir()
 {
-	static char *basedir;
-
-	if (!basedir) {
-	    char *th = getenv ("TELHOME");
-	    if (th) {
-		basedir = malloc (strlen(th) + 10);
-		if (basedir) {
-		    (void) sprintf (basedir, "%s/xephem", th);
-		    if (existsh(basedir) < 0) {
-			(void) sprintf (basedir, "%s/archive", th);
-			if (existsh(basedir) < 0) {
-			    free (basedir);
-			    basedir = NULL;
-			}
-		    }
-		}
-	    }
-	    if (!basedir) {
-		char *homebase = expand_home (getXRes ("ShareDir", "."));
-		basedir = strcpy(malloc(strlen(homebase)+1), homebase);
-	    }
-	}
-
-	return (basedir);
-
+  /*
+   *  pkgsrc: just use pkgsrc version, for now, because a twisty maze
+   *  of Xt calls wrongly returns "." for no apparent reason
+   */
+  return("@SHAREDIR@");
 }
 
 /* return a string for whatever is in errno right now.
@@ -227,7 +210,6 @@ syserrstr ()
 {
 #if defined(__STDC__)
 /* some older gcc don't have strerror */
-#include <errno.h>
 return (strerror (errno));
 #else
 #if defined(VMS)
