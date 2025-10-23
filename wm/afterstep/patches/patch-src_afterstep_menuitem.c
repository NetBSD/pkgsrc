$NetBSD: patch-src_afterstep_menuitem.c,v 1.2 2025/10/23 01:28:09 gutteridge Exp $

Need function prototype for XkbKeycodeToKeysym(3).
Use ctype.h correctly.

--- src/afterstep/menuitem.c.orig	2013-05-01 13:34:11.000000000 +0000
+++ src/afterstep/menuitem.c
@@ -53,6 +53,8 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 
+#include <X11/XKBlib.h>
+
 #include "dirtree.h"
 
 /***************************************************************************/
@@ -64,7 +66,7 @@ MenuData *FindPopup (const char *name, i
 
 	if (name == NULL) {
 		if (!quiet)
-			show_error ("Empty Popup name specifyed");
+			show_error ("Empty Popup name specified");
 		return md;
 	}
 
@@ -100,7 +102,7 @@ Bool MenuDataItemParse (void *data, cons
 
 	if (buf == NULL)
 		return False;
-	for (; isspace (*buf); buf++) ;
+	for (; isspace ((unsigned char)*buf); buf++) ;
 	if (*buf == '\0' || *buf == '#' || *buf == '*')
 		return False;
 
@@ -126,7 +128,7 @@ Bool FunctionItemParse (void *data, cons
 
 	if (buf == NULL)
 		return False;
-	for (; isspace (*buf); buf++) ;
+	for (; isspace ((unsigned char)*buf); buf++) ;
 	if (*buf == '\0' || *buf == '#' || *buf == '*')
 		return False;
 
@@ -163,7 +165,7 @@ ParseBody (void *data, FILE * fd, Bool (
 	buf = safemalloc (MAXLINELENGTH + 1);
 	while ((ptr = fgets (buf, MAXLINELENGTH, fd)) != NULL) {
 		LOCAL_DEBUG_OUT ("parsing Popup line \"%s\"", buf);
-		while (isspace (*ptr))
+		while (isspace ((unsigned char)*ptr))
 			ptr++;
 		if (!item_func (data, ptr))
 			if (mystrncasecmp ("End", ptr, 3) == 0) {
@@ -215,9 +217,9 @@ void ParseMouseEntry (char *tline, FILE 
 	int contexts, mods;
 	FunctionData *fdata;
 
-	while (isspace (*tline))
+	while (isspace ((unsigned char)*tline))
 		tline++;
-	while (isdigit (*tline)) {
+	while (isdigit ((unsigned char)*tline)) {
 		button = button * 10 + (int)((*tline) - '0');
 		tline++;
 	}
