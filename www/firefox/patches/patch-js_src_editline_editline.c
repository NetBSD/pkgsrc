$NetBSD: patch-js_src_editline_editline.c,v 1.1 2025/07/26 14:12:54 ryoon Exp $

--- js/src/editline/editline.c.orig	2025-07-26 13:19:29.740302059 +0000
+++ js/src/editline/editline.c
@@ -337,11 +337,11 @@ do_forward(STATUS move)
     i = 0;
     do {
 	p = &Line[Point];
-	for ( ; Point < End && (*p == ' ' || !isalnum(*p)); Point++, p++)
+	for ( ; Point < End && (*p == ' ' || !isalnum((unsigned char)(*p))); Point++, p++)
 	    if (move == CSmove)
 		right(CSstay);
 
-	for (; Point < End && isalnum(*p); Point++, p++)
+	for (; Point < End && isalnum((unsigned char)(*p)); Point++, p++)
 	    if (move == CSmove)
 		right(CSstay);
 
@@ -1166,10 +1166,10 @@ bk_word()
 
     i = 0;
     do {
-	for (p = &Line[Point]; p > Line && !isalnum(p[-1]); p--)
+	for (p = &Line[Point]; p > Line && !isalnum((unsigned char)(p[-1])); p--)
 	    left(CSmove);
 
-	for (; p > Line && p[-1] != ' ' && isalnum(p[-1]); p--)
+	for (; p > Line && p[-1] != ' ' && isalnum((unsigned char)(p[-1])); p--)
 	    left(CSmove);
 
 	if (Point == 0)
