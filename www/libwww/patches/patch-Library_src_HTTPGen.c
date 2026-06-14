$NetBSD: patch-Library_src_HTTPGen.c,v 1.1 2026/06/14 12:57:43 nia Exp $

Fix ctype usage.

--- Library/src/HTTPGen.c.orig	2026-06-14 12:53:36.556710502 +0000
+++ Library/src/HTTPGen.c
@@ -140,7 +140,7 @@ PRIVATE int HTTPGenMake (HTStream * me, HTRequest * re
 		if (name && *name) {
 		    char * ptr = name;
 		    while (*ptr) {
-			if (isspace(*ptr)) *ptr='_';
+			if (isspace((unsigned char)*ptr)) *ptr='_';
 			ptr++;
 		    }
 		    PUTS(name);
@@ -148,7 +148,7 @@ PRIVATE int HTTPGenMake (HTStream * me, HTRequest * re
 		    if (value) {
 			ptr = value;
 			while (*ptr) {
-			    if (isspace(*ptr)) *ptr=' ';
+			    if (isspace((unsigned char)*ptr)) *ptr=' ';
 			    ptr++;
 			}
 			PUTS(value);
