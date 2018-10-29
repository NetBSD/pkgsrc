$NetBSD: patch-gtk_gtkfontchooserwidget.c,v 1.1 2018/10/29 21:35:17 leot Exp $

Correctly include freetype2 headers (<ft2build.h> and then macros
should be used instead of directly including the headers).

--- gtk/gtkfontchooserwidget.c.orig	2018-07-18 11:04:31.000000000 +0000
+++ gtk/gtkfontchooserwidget.c
@@ -58,8 +58,9 @@
 #include <hb.h>
 #include <hb-ot.h>
 #include <hb-ft.h>
-#include <freetype/freetype.h>
-#include <freetype/ftmm.h>
+#include <ft2build.h>
+#include FT_FREETYPE_H
+#include FT_MULTIPLE_MASTERS_H
 #include "language-names.h"
 #include "script-names.h"
 #endif
