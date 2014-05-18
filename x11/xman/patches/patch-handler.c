$NetBSD: patch-handler.c,v 1.1 2014/05/18 21:26:02 joerg Exp $

--- handler.c.orig	2014-05-16 15:36:10.000000000 +0000
+++ handler.c
@@ -320,7 +320,7 @@ SaveFormattedPage(Widget w, XEvent * eve
  * If we are not active then take no action.
  */
 
-    if (man_globals->tempfile == NULL)
+    if (man_globals->tempfile[0] == '\0')
         return;
 
     switch (params[0][0]) {
