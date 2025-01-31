$NetBSD: patch-FL_Fl__Cairo.H,v 1.1 2025/01/31 12:22:44 micha Exp $

Include header "cairo.h" from subdirectory "cairo".
The rest of the sourcecode already do this.

--- FL/Fl_Cairo.H.orig	2024-12-12 17:45:50.000000000 +0000
+++ FL/Fl_Cairo.H
@@ -37,7 +37,7 @@
 
 # ifdef FLTK_HAVE_CAIRO
 
-# include <cairo.h>
+# include <cairo/cairo.h>
 
 /**
   \addtogroup group_cairo
