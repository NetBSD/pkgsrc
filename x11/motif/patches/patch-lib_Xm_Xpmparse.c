$NetBSD: patch-lib_Xm_Xpmparse.c,v 1.1 2022/04/05 09:59:56 riastradh Exp $

Fix ctype(3) abuse.

--- lib/Xm/Xpmparse.c.orig	2017-03-27 22:24:31.000000000 +0000
+++ lib/Xm/Xpmparse.c
@@ -728,7 +728,7 @@ xpmParseExtensions(data, extensions, nex
 	ext += num;
 	/* skip whitespace and store its name */
 	s2 = s = string + 6;
-	while (isspace(*s2))
+	while (isspace((unsigned char)*s2))
 	    s2++;
 	a = s2 - s;
 	ext->name = (char *) XpmMalloc(l - a - 6);
