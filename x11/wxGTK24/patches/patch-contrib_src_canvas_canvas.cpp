$NetBSD: patch-contrib_src_canvas_canvas.cpp,v 1.1 2014/03/22 16:50:29 spz Exp $

make it deal gracefully with both freetype 2.4.* and 2.5.*

--- contrib/src/canvas/canvas.cpp.orig	2003-09-21 11:32:40.000000000 +0000
+++ contrib/src/canvas/canvas.cpp
@@ -32,7 +32,8 @@
 #endif
 
 #if wxUSE_FREETYPE
-    #include <freetype/freetype.h>
+    #include <ft2build.h>
+    #include FT_FREETYPE_H
 #endif
 
 //#define CANVASDEBUG
