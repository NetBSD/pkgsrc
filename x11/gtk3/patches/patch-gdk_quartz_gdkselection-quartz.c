$NetBSD: patch-gdk_quartz_gdkselection-quartz.c,v 1.1 2020/01/08 14:57:29 adam Exp $

https://gitlab.gnome.org/GNOME/gtk/issues/2279

--- gdk/quartz/gdkselection-quartz.c.orig	2020-01-08 14:36:55.000000000 +0000
+++ gdk/quartz/gdkselection-quartz.c
@@ -24,6 +24,7 @@
 #include "gdkproperty.h"
 #include "gdkquartz.h"
 #include "gdkinternal-quartz.h"
+#include "gdkquartz-gtk-only.h"
 
 gboolean
 _gdk_quartz_display_set_selection_owner (GdkDisplay *display,
