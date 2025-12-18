$NetBSD: patch-widgets.c,v 1.2 2025/12/18 13:18:18 nia Exp $

Include <strings.h> for index(3).

Fix sprintf() usage.

--- widgets.c.orig	2011-07-09 09:51:18.000000000 +0000
+++ widgets.c
@@ -3,6 +3,7 @@
 #include <sys/timeb.h>
 #include <sys/stat.h>
 #include <string.h>
+#include <strings.h>
 
 #include "sunclock.h"
 #include "langdef.h"
@@ -818,13 +819,13 @@ char *hint;
 	if (key == '=')
 	    sprintf(more+2, "(%c)", (do_sync)? '+' : '-');
 	if (key == '[' && do_root <= 0)
-	    sprintf(more+2, Label[L_ONCE]);
+	    sprintf(more+2, "%s", Label[L_ONCE]);
 	if (key == '[' && do_root >= 1)
 	    sprintf(more+2, Label[L_PERIODIC], root_period);
 	if (key == ']' && do_root <= 0)
-	    sprintf(more+2, Label[L_BLANKSCREEN]);
+	    sprintf(more+2, "%s", Label[L_BLANKSCREEN]);
 	if (key == ']' && do_root >= 1)
-	    sprintf(more+2, Label[L_STARRYSKY]);
+	    sprintf(more+2, "%s", Label[L_STARRYSKY]);
         if (more[2])
 	   strncat(hint, more, 120 - strlen(hint));
         l = strlen(hint);
