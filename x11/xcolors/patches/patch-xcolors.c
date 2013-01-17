$NetBSD: patch-xcolors.c,v 1.1 2013/01/17 16:06:49 joerg Exp $

--- xcolors.c.orig	2013-01-16 14:05:59.000000000 +0000
+++ xcolors.c
@@ -26,12 +26,16 @@ static char*id="$XConsortium: xcolors.c,
 #include <X11/Xaw/Label.h>
 #include <stdio.h>
 #include <ctype.h>
+#include <stdlib.h>
 #include <math.h>		/* for sqrt() */
 
 #ifndef RGB_TXT
 #define RGB_TXT "/usr/lib/X11/rgb.txt"
 #endif
 
+static int l_strcasecmp(char *s1, char *s2);
+static void colordemo(Widget parent, char *startcolor, XColor nearcolor, int maxdist);
+
 String fallback_resources[] = {
     "*Label.Font: 5x7",
     "*panes.Width: 985",
@@ -274,11 +278,7 @@ main(argc, argv)
     /* NOTREACHED */
 }
 
-colordemo(parent, startcolor, nearcolor, maxdist)
-     Widget parent;
-     char *startcolor;
-     XColor nearcolor;		/* scaled 0-255 */
-     int maxdist;
+static void colordemo(Widget parent, char *startcolor, XColor nearcolor, int maxdist)
 {
     int r, g, b, prev_r, prev_g, prev_b;
     char rgb_line[100];
@@ -373,9 +373,8 @@ do_color(parent, colorname)
  * Similar to strcmp, but ignores case.
  * Always returns 1 if different.
  */
-int
-l_strcasecmp(s1, s2)
-     char *s1, *s2;
+static int
+l_strcasecmp(char *s1, char *s2)
 {
     for ( ; *s1 && *s2 ; s1++, s2++)
       if ((isupper(*s1) ? tolower(*s1) : *s1) !=
