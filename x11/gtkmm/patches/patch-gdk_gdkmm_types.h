$NetBSD: patch-gdk_gdkmm_types.h,v 1.2 2013/05/26 09:14:57 adam Exp $

Fix missing dependencies.

--- gdk/gdkmm/types.h.orig	2013-04-05 03:20:58.000000000 +0000
+++ gdk/gdkmm/types.h
@@ -3,7 +3,9 @@
 #ifndef _GDKMM_TYPES_H
 #define _GDKMM_TYPES_H
 
-
+#include <glibmm/arrayhandle.h>
+#include <glibmm/listhandle.h>
+#include <glibmm/value.h>
 #include <glibmm/ustring.h>
 #include <sigc++/sigc++.h>
 
