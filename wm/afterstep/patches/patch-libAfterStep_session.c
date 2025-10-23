$NetBSD: patch-libAfterStep_session.c,v 1.2 2025/10/23 01:28:08 gutteridge Exp $

Actually provide a useful error state when failing to open files
or directories.
Use ctype.h correctly.

--- libAfterStep/session.c.orig	2013-05-01 13:34:11.000000000 +0000
+++ libAfterStep/session.c
@@ -563,8 +563,9 @@ static int MakeASDir (const char *name, 
 	show_progress ("Creating %s ... ", name);
 	if (mkdir (name, perms)) {
 		show_error
-				("AfterStep depends on %s directory !\nPlease check permissions or contact your sysadmin !",
-				 name);
+				("AfterStep depends on the %s directory, error \"%s\"!\n"
+				" Please check permissions or contact your sysadmin!",
+				 name, strerror(errno));
 		return (-1);
 	}
 	show_progress ("\t created.");
@@ -577,9 +578,9 @@ static int MakeASFile (const char *name)
 
 	show_progress ("Creating %s ... ", name);
 	if ((touch = fopen (name, "w")) == NULL) {
-		show_error ("Cannot open file %s for writing!\n"
-								" Please check permissions or contact your sysadmin !",
-								name);
+		show_error ("Cannot open file %s for writing, error \"%s\"!\n"
+					" Please check permissions or contact your sysadmin!",
+					name, strerror(errno));
 		return (-1);
 	}
 	fclose (touch);
@@ -1076,7 +1077,7 @@ char *make_session_webcache_file (ASSess
 		for (i = 0; url[i]; ++i) {
 			if (url[i] == '_')
 				escapedUrl[len++] = '_';
-			if (url[i] != '.' && url[i] != '_' && !isalnum (url[i]))
+			if (url[i] != '.' && url[i] != '_' && !isalnum ((unsigned char)url[i]))
 				escapedUrl[len++] = '_';
 			else
 				escapedUrl[len++] = url[i];
