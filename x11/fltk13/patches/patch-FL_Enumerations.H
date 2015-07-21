$NetBSD: patch-FL_Enumerations.H,v 1.1 2015/07/21 21:36:41 markd Exp $

part of tigervnc.patch from archlinux package.

--- FL/Enumerations.H.orig	2014-10-15 21:00:20.000000000 +0000
+++ FL/Enumerations.H
@@ -909,27 +909,27 @@ inline Fl_Color fl_color_cube(int r, int
 /* FIXME: We should renumber these, but that will break the ABI */
 enum Fl_Cursor {
   FL_CURSOR_DEFAULT    =  0, /**< the default cursor, usually an arrow. */
-  FL_CURSOR_ARROW      = 35, /**< an arrow pointer. */
-  FL_CURSOR_CROSS      = 66, /**< crosshair. */
-  FL_CURSOR_WAIT       = 76, /**< busy indicator (e.g. hourglass). */
-  FL_CURSOR_INSERT     = 77, /**< I-beam. */
-  FL_CURSOR_HAND       = 31, /**< pointing hand. */
-  FL_CURSOR_HELP       = 47, /**< question mark pointer. */
-  FL_CURSOR_MOVE       = 27, /**< 4-pointed arrow or hand. */
+  FL_CURSOR_ARROW      = 1, /**< an arrow pointer. */
+  FL_CURSOR_CROSS      = 2, /**< crosshair. */
+  FL_CURSOR_WAIT       = 3, /**< busy indicator (e.g. hourglass). */
+  FL_CURSOR_INSERT     = 4, /**< I-beam. */
+  FL_CURSOR_HAND       = 5, /**< pointing hand. */
+  FL_CURSOR_HELP       = 6, /**< question mark pointer. */
+  FL_CURSOR_MOVE       = 7, /**< 4-pointed arrow or hand. */
 
   /* Resize indicators */
-  FL_CURSOR_NS         = 78, /**< up/down resize. */
-  FL_CURSOR_WE         = 79, /**< left/right resize. */
-  FL_CURSOR_NWSE       = 80, /**< diagonal resize. */
-  FL_CURSOR_NESW       = 81, /**< diagonal resize. */
-  FL_CURSOR_N          = 70, /**< upwards resize. */
-  FL_CURSOR_NE         = 69, /**< upwards, right resize. */
-  FL_CURSOR_E          = 49, /**< rightwards resize. */
-  FL_CURSOR_SE         =  8, /**< downwards, right resize. */
-  FL_CURSOR_S          =  9, /**< downwards resize. */
-  FL_CURSOR_SW         =  7, /**< downwards, left resize. */
-  FL_CURSOR_W          = 36, /**< leftwards resize. */
-  FL_CURSOR_NW         = 68, /**< upwards, left resize. */
+  FL_CURSOR_NS         = 101, /**< up/down resize. */
+  FL_CURSOR_WE         = 102, /**< left/right resize. */
+  FL_CURSOR_NWSE       = 103, /**< diagonal resize. */
+  FL_CURSOR_NESW       = 104, /**< diagonal resize. */
+  FL_CURSOR_NE         = 110, /**< upwards, right resize. */
+  FL_CURSOR_N          = 111, /**< upwards resize. */
+  FL_CURSOR_NW         = 112, /**< upwards, left resize. */
+  FL_CURSOR_E          = 113, /**< rightwards resize. */
+  FL_CURSOR_W          = 114, /**< leftwards resize. */
+  FL_CURSOR_SE         = 115, /**< downwards, right resize. */
+  FL_CURSOR_S          = 116, /**< downwards resize. */
+  FL_CURSOR_SW         = 117, /**< downwards, left resize. */
 
   FL_CURSOR_NONE       =255  /**< invisible. */
 };
