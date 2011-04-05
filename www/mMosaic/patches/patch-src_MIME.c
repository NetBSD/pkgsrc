$NetBSD: patch-src_MIME.c,v 1.1 2011/04/05 12:27:06 wiz Exp $

Fix conflict in prototypes with NetBSD native getline().

--- src/MIME.c.orig	2000-10-12 12:30:15.000000000 +0000
+++ src/MIME.c
@@ -311,7 +311,7 @@ static void HTSetSuffix ( const char *su
 
 #define MAX_STRING_LEN 256
 
-static int getline(char *s, int n, FILE *f) 
+static int mm_getline(char *s, int n, FILE *f) 
 {
 	register int i=0;
   
@@ -353,7 +353,7 @@ static void HTLoadExtensionsConfigFile (
 		return ;
 	}
 
-	while(!(getline(l,MAX_STRING_LEN,f))) {
+	while(!(mm_getline(l,MAX_STRING_LEN,f))) {
 /* always get rid of leading white space for "line" -- SWP */
 		for (ptr=l; *ptr && isspace(*ptr); ptr++)
 			;
