$NetBSD: patch-gtk_gtkfontchooserwidget.c,v 1.3 2022/01/12 11:09:07 adam Exp $

Correctly include freetype2 headers (<ft2build.h> and then macros
should be used instead of directly including the headers).

Issue opened upstream as:

 <https://gitlab.gnome.org/GNOME/gtk/issues/1432> 

--- gtk/gtkfontchooserwidget.c.orig	2021-12-11 02:50:17.000000000 +0000
+++ gtk/gtkfontchooserwidget.c
@@ -66,8 +66,9 @@
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
 #elif defined (HAVE_FONT_FEATURES)
