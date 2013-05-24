$NetBSD: patch-gdk_gdkmm_color.h,v 1.1 2013/05/24 19:31:59 joerg Exp $

--- gdk/gdkmm/color.h.orig	2013-05-24 17:18:47.000000000 +0000
+++ gdk/gdkmm/color.h
@@ -5,7 +5,7 @@
 
 #include <gdkmmconfig.h>
 
-
+#include <glibmm/arrayhandle.h>
 #include <glibmm/ustring.h>
 #include <sigc++/sigc++.h>
 
