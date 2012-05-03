$NetBSD: patch-gtksourceview_gtksourcelanguage.c,v 1.1 2012/05/03 06:06:13 wiz Exp $

Adapt for glib-2.32.

--- gtksourceview/gtksourcelanguage.c.orig	2007-01-03 15:40:28.000000000 +0000
+++ gtksourceview/gtksourcelanguage.c
@@ -30,8 +30,7 @@
 
 #include <libxml/xmlreader.h>
 
-#include <glib/gstdio.h>
-#include <glib/gmappedfile.h>
+#include <glib.h>
 
 #include "gtksourceview-i18n.h"
 
