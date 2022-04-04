$NetBSD: patch-src_Panner.c,v 1.2 2022/04/04 12:55:28 wiz Exp $

Fix ctype(3) use.
https://gitlab.freedesktop.org/xorg/lib/libxaw/-/merge_requests/11

--- src/Panner.c.orig	2021-03-27 17:40:21.000000000 +0000
+++ src/Panner.c
@@ -575,7 +575,7 @@ parse_page_string(String s, int pagesize
     /*
      * syntax:    spaces [+-] number spaces [pc\0] spaces
      */
-    for (; isascii(*s) && isspace(*s); s++)	/* skip white space */
+    for (; isascii((unsigned char)*s) && isspace((unsigned char)*s); s++)	/* skip white space */
 	;
 
     if (*s == '+' || *s == '-')	{		/* deal with signs */
@@ -590,12 +590,12 @@ parse_page_string(String s, int pagesize
     }
 
 					/* skip over numbers */
-    for (cp = s; isascii(*s) && (isdigit(*s) || *s == '.'); s++)
+    for (cp = s; isascii((unsigned char)*s) && (isdigit((unsigned char)*s) || *s == '.'); s++)
 	;
     val *= atof(cp);
 
 					/* skip blanks */
-    for (; isascii(*s) && isspace(*s); s++)
+    for (; isascii((unsigned char)*s) && isspace((unsigned char)*s); s++)
 	;
 
     if (*s) {				/* if units */
