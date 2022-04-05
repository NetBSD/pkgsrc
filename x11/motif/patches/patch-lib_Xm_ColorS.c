$NetBSD: patch-lib_Xm_ColorS.c,v 1.1 2022/04/05 09:59:56 riastradh Exp $

Fix ctype(3) abuse.

--- lib/Xm/ColorS.c.orig	2016-03-16 02:10:08.000000000 +0000
+++ lib/Xm/ColorS.c
@@ -846,7 +846,7 @@ EndsInDigits(char *str)
     register char *c = str;
     while(*c != '\0') c++;	/* advance to end of string marker */
     c--;			/* back to the last character */
-    if(c >= str && isascii(*c) && isdigit(*c)) 
+    if(c >= str && isascii((unsigned char)*c) && isdigit((unsigned char)*c)) 
 	return True;
     
     return False;
@@ -1307,15 +1307,15 @@ read_rgb_file(XmColorSelectorWidget csw,
 		/*
 		 * Copy in all characters that are ascii and non-spaces.
 		 */
-		if (!isascii(c))
+		if (!isascii((unsigned char)c))
 		    continue;
-		if (!isspace(c))
-		    *name++ = tolower(c);
+		if (!isspace((unsigned char)c))
+		    *name++ = tolower((unsigned char)c);
 	    }
 	    *name = '\0';
 
 	    name = color_info[count].name;
-	    color_name[0] = toupper(color_name[0]);
+	    color_name[0] = toupper((unsigned char)color_name[0]);
 	    for (i = 0; i < len; i++) {
 		register char c = color_name[i];
 
@@ -1323,10 +1323,10 @@ read_rgb_file(XmColorSelectorWidget csw,
 		 * Capitalize all characters after a space.
 		 */
 
-		if (!isascii(c))
+		if (!isascii((unsigned char)c))
 		    continue;
-		if (isspace(c) && ((i + 1) < len)) {
-		    color_name[i + 1] = toupper(color_name[i + 1]);
+		if (isspace((unsigned char)c) && ((i + 1) < len)) {
+		    color_name[i + 1] = toupper((unsigned char)color_name[i + 1]);
 		}
 
 		*name++ = c;
@@ -1452,7 +1452,7 @@ find_name(char *buffer)
 	 * Look for first non number, non space or tab.
 	 */
     
-	if (isascii(*curr) && (isdigit(*curr) || isspace(*curr)))
+	if (isascii((unsigned char)*curr) && (isdigit((unsigned char)*curr) || isspace((unsigned char)*curr)))
 	    continue;
 
 	temp = (char *) strchr(curr, '\n');
