$NetBSD: patch-config.h,v 1.1 2020/10/11 08:56:37 nia Exp $

Use a font that might actually be installed.

Avoid Motif dependency.

--- config.h.orig	2004-11-21 18:17:42.000000000 +0000
+++ config.h
@@ -4,7 +4,7 @@
 
 /* default settings */
 
-#define DEF_FONT	"variable"
+#define DEF_FONT	"fixed"
 #define DEF_ABG		"steel blue"    /*background for active windows*/
 #define DEF_BG		"grey50"        /*background for inactive windows*/
 #define DEF_FG		"snow"          /*color for window title*/
@@ -22,7 +22,7 @@
 
 /*  Use Motif hints to find if a window should be borderless.
  To use this option, you need to have the Motif development files installed. */
-#define  MWM_HINTS
+/* #define  MWM_HINTS */
 
 /* You can save a few bytes if you know you won't need colour map support
 (eg for 16 or more bit displays) */
