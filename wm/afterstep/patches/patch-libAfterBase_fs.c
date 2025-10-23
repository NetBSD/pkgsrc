$NetBSD: patch-libAfterBase_fs.c,v 1.1 2025/10/23 01:28:08 gutteridge Exp $

Use ctype.h correctly.

--- libAfterBase/fs.c.orig	2013-05-01 13:34:11.000000000 +0000
+++ libAfterBase/fs.c
@@ -377,7 +377,7 @@ find_envvar (char *var_start, int *end_p
 		tmp[i-1] = '\0' ;
 	} else
 	{	
-		for (i = 0; (isalnum ((int)var_start[i]) || var_start[i] == '_') && i < 255; i++)
+		for (i = 0; (isalnum ((unsigned char)var_start[i]) || var_start[i] == '_') && i < 255; i++)
 			tmp[i] = var_start[i] ;
 		tmp[i] = '\0';
 	}		
@@ -520,14 +520,14 @@ get_executable_in_path (const char *name
 	}
 
 	/* cut leading "exec" enclosed in spaces */
-	for (; isspace ((int)*name); name++);
-	if (!mystrncasecmp(name, "exec", 4) && isspace ((int)name[4]))
+	for (; isspace ((unsigned char)*name); name++);
+	if (!mystrncasecmp(name, "exec", 4) && isspace ((unsigned char)name[4]))
 		name += 4;
-	for (; isspace ((int)*name); name++);
+	for (; isspace ((unsigned char)*name); name++);
 	if (*name == '\0')
 		return 0;
 
-	for (i = 0; name[i] && !isspace ((int)name[i]); i++);
+	for (i = 0; name[i] && !isspace ((unsigned char)name[i]); i++);
 	if (i == 0)
 		return 0;
 
