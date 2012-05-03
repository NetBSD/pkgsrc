$NetBSD: patch-gtksourceview_gtksourceregex.h,v 1.1 2012/05/03 06:06:13 wiz Exp $

Adapt for glib-2.32.

--- gtksourceview/gtksourceregex.h.orig	2007-01-03 15:40:28.000000000 +0000
+++ gtksourceview/gtksourceregex.h
@@ -20,7 +20,7 @@
 #ifndef __GTK_SOURCE_REGEX_H__
 #define __GTK_SOURCE_REGEX_H__
 
-#include <glib/gtypes.h>
+#include <glib.h>
 
 G_BEGIN_DECLS
 
