$NetBSD: patch-src_XawIm.c,v 1.1 2022/04/04 12:42:19 riastradh Exp $

Fix ctype(3) abuse.

--- src/XawIm.c.orig	2021-03-27 17:40:21.000000000 +0000
+++ src/XawIm.c
@@ -472,14 +472,14 @@ OpenIM(XawVendorShellExtPart *ve)
 
 	for(ns=s=ve->im.input_method; ns && *s;) {
 	    /* skip any leading blanks */
-	    while (*s && isspace(*s)) s++;
+	    while (*s && isspace((unsigned char)*s)) s++;
 	    if (!*s) break;
 	    if ((ns = end = strchr(s, ',')) == NULL)
 		end = s + strlen(s);
 	    /* If there is a spurious comma end can be the same as s */
 	    if (end > s) {
 		/* strip any trailing blanks */
-		while (isspace(*(end - 1))) end--;
+		while (isspace((unsigned char)*(end - 1))) end--;
 
 		strcpy (pbuf, "@im=");
 		strncat (pbuf, s, (size_t)(end - s));
@@ -514,14 +514,14 @@ OpenIM(XawVendorShellExtPart *ve)
     }
     found = False;
     for(ns = s = ve->im.preedit_type; s && !found;) {
-	while (*s && isspace(*s)) s++;
+	while (*s && isspace((unsigned char)*s)) s++;
 	if (!*s) break;
 	if ((ns = end = strchr(s, ',')) == NULL)
 	    end = s + strlen(s);
 	else
 	    ns++;
 	if (end > s)
-	    while (isspace(*(end - 1))) end--;
+	    while (isspace((unsigned char)*(end - 1))) end--;
 
 	if (!strncmp(s, "OverTheSpot", (size_t)(end - s))) {
 	    input_style = (XIMPreeditPosition | XIMStatusArea);
