$NetBSD: patch-unclutter.c,v 1.1 2025/09/19 06:24:26 mrg Exp $

Port to modern C.

--- unclutter.c.orig	1994-04-11 08:40:47.000000000 -0700
+++ unclutter.c	2025-09-18 23:17:22.053941452 -0700
@@ -24,13 +24,17 @@
 #include <X11/Xutil.h>
 #include <X11/Xproto.h>
 #include <stdio.h>
+#include <stdlib.h>
 #include "vroot.h"
 
 char *progname;
-pexit(str)char *str;{
+void
+pexit(char *str)
+{
     fprintf(stderr,"%s: %s\n",progname,str);
     exit(1);
 }
+void
 usage(){
     pexit("usage:\n\
 	-display <display>\n\
@@ -58,9 +62,7 @@
  * ignore these errors.
  */
 int (*defaulthandler)();
-int errorhandler(display,error)
-Display *display;
-XErrorEvent *error;
+int errorhandler(Display *display, XErrorEvent *error)
 {
     if(error->error_code!=BadWindow)
 	(*defaulthandler)(display,error);
@@ -72,9 +74,8 @@
  * return true if window has a wm_name and the start of it matches
  * one of the given names to avoid
  */
-nameinlist(display,window)
-Display *display;
-Window window;
+int
+nameinlist(Display *display, Window window)
 {
     char **cpp;
     char *name;
@@ -93,9 +94,8 @@
 /*
  * create a small 1x1 curssor with all pixels masked out on the given screen.
  */
-createnullcursor(display,root)
-Display *display;
-Window root;
+Cursor
+createnullcursor(Display *display, Window root)
 {
     Pixmap cursormask;
     XGCValues xgc;
@@ -117,7 +117,8 @@
     return cursor;
 }
 
-main(argc,argv)char **argv;{
+int
+main(int argc, char **argv){
     Display *display;
     int screen,oldx = -99,oldy = -99,numscreens;
     int doroot = 0, jitter = 0, idletime = 5, usegrabmethod = 0, waitagain = 0,
