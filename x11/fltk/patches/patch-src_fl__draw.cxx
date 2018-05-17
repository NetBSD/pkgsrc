$NetBSD: patch-src_fl__draw.cxx,v 1.1 2018/05/17 10:37:23 jperkin Exp $

Use std::min correctly.

--- src/fl_draw.cxx.orig	2006-12-21 19:39:26.000000000 +0000
+++ src/fl_draw.cxx
@@ -32,14 +32,17 @@
 // Expands all unprintable characters to ^X or \nnn notation
 // Aligns them against the inside of the box.
 
-#define min(a,b) ((a)<(b)?(a):(b))
+//#define min(a,b) ((a)<(b)?(a):(b))
 #include <FL/fl_draw.H>
 #include <FL/Fl_Image.H>
 
 #include "flstring.h"
+#include <algorithm>
 #include <ctype.h>
 #include <math.h>
 
+using std::min;
+
 #define MAXBUF 1024
 
 char fl_draw_shortcut;	// set by fl_labeltypes.cxx
