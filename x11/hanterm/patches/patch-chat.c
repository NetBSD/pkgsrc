$NetBSD: patch-chat.c,v 1.1 2013/11/24 05:53:52 dholland Exp $

- use standard headers
- don't cast the result of calloc

--- chat.c~	2001-06-06 13:05:15.000000000 +0000
+++ chat.c
@@ -11,6 +11,7 @@
 #include "error.h"
 #include "hangul.h"
 #include <stdio.h>
+#include <stdlib.h>
 #include <X11/keysym.h>
 
 #define MAXCHATBUF 1024
@@ -61,7 +62,7 @@ toggle_chat_mode(str)
             chat_x += ST_KBD_LEN;
 
 	if (chat_buf == NULL) {
-	    chat_buf = (Char *)calloc((unsigned)MAXCHATBUF, sizeof(Char));
+	    chat_buf = calloc((unsigned)MAXCHATBUF, sizeof(Char));
 	    if (chat_buf == NULL) {
 		fprintf(stderr, "%s: can't allocate chat buf\n", xterm_name);
 		Cleanup(ERROR_SCALLOC);
