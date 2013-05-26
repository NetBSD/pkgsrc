$NetBSD: patch-gdk_gdkmm_pixbufanimationiter.h,v 1.1 2013/05/26 09:14:57 adam Exp $

Fix missing dependencies.

--- gdk/gdkmm/pixbufanimationiter.h.orig	2013-05-26 08:29:31.000000000 +0000
+++ gdk/gdkmm/pixbufanimationiter.h
@@ -29,6 +29,7 @@
  */
 
 #include <glibmm/object.h>
+#include <glibmm/timeval.h>
 #include <gdkmm/pixbuf.h>
 #include <gdk-pixbuf/gdk-pixbuf.h>
 
