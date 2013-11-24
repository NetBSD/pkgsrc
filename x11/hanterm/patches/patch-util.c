$NetBSD: patch-util.c,v 1.1 2013/11/24 05:53:52 dholland Exp $

- use standard headers
- don't cast result of malloc

--- util.c~	1999-03-05 06:59:09.000000000 +0000
+++ util.c
@@ -33,6 +33,7 @@
 #include "menu.h"
 
 #include <stdio.h>
+#include <stdlib.h>
 
 extern void HideCursor();
 extern void ScrollBarReverseVideo();
@@ -1126,8 +1127,8 @@ int xstrcasecmp(s1, s2)
   int i, r;
   char *t1, *t2;
 
-  t1 = (char *)malloc(strlen(s1)+1);
-  t2 = (char *)malloc(strlen(s2)+1);
+  t1 = malloc(strlen(s1)+1);
+  t2 = malloc(strlen(s2)+1);
 
   for(i=0; s1[i]; i++) t1[i] = x2lower(s1[i]);
   t1[i] = 0;
@@ -1147,8 +1148,8 @@ int xstrncasecmp(s1, s2, n)
   int i, r;
   char *t1, *t2;
 
-  t1 = (char *)malloc(strlen(s1)+1);
-  t2 = (char *)malloc(strlen(s2)+1);
+  t1 = malloc(strlen(s1)+1);
+  t2 = malloc(strlen(s2)+1);
 
   for(i=0; s1[i]; i++) t1[i] = x2lower(s1[i]);
   t1[i] = 0;
