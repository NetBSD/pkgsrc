$NetBSD: patch-gtk_gtkmm_main.h,v 1.1 2013/05/24 19:31:59 joerg Exp $

--- gtk/gtkmm/main.h.orig	2013-04-05 01:24:23.000000000 +0000
+++ gtk/gtkmm/main.h
@@ -3,7 +3,7 @@
 #ifndef _GTKMM_MAIN_H
 #define _GTKMM_MAIN_H
 
-
+#include <glibmm/optioncontext.h>
 #include <glibmm/ustring.h>
 #include <sigc++/sigc++.h>
 
