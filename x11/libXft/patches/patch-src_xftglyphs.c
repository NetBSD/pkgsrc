$NetBSD: patch-src_xftglyphs.c,v 1.1 2014/03/15 09:20:31 richard Exp $
Use FT_*_H macros instead of including <freetype/*.h>
http://lists.freedesktop.org/archives/xorg-devel/2013-December/039310.html
and
http://lists.freedesktop.org/archives/xorg-devel/2013-December/039311.html

--- src/xftglyphs.c.orig	2012-06-02 16:36:35.000000000 +0000
+++ src/xftglyphs.c
@@ -21,10 +21,10 @@
  */
 
 #include "xftint.h"
-#include <freetype/ftoutln.h>
-#include <freetype/ftlcdfil.h>
-
-#include <freetype/ftsynth.h>
+#include <ft2build.h>
+#include FT_FREETYPE_H
+#include FT_LCD_FILTER_H
+#include FT_SYNTHESIS_H
 
 /*
  * Validate the memory info for a font
