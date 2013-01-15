$NetBSD: patch-xcolorsel.c,v 1.1 2013/01/15 16:21:36 morr Exp $

--- xcolorsel.c.orig	1994-11-13 22:16:59.000000000 +0000
+++ xcolorsel.c
@@ -53,7 +53,6 @@
 #include <unistd.h>
 #include <string.h>
 #include <errno.h>
-#include <malloc.h>
 #include <fcntl.h>
 
 #include <X11/Xlib.h>
