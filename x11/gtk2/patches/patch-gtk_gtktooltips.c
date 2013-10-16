$NetBSD: patch-gtk_gtktooltips.c,v 1.1 2013/10/16 10:59:13 jperkin Exp $

Avoid multi-line comments after macros, it can confuse parsers.

--- gtk/gtktooltips.c.orig	2011-08-16 02:30:52.000000000 +0000
+++ gtk/gtktooltips.c
@@ -45,12 +45,8 @@
 
 
 #define DEFAULT_DELAY 500           /* Default delay in ms */
-#define STICKY_DELAY 0              /* Delay before popping up next tip
-                                     * if we're sticky
-                                     */
-#define STICKY_REVERT_DELAY 1000    /* Delay before sticky tooltips revert
-				     * to normal
-                                     */
+#define STICKY_DELAY 0              /* Delay before popping up next tip if we're sticky */
+#define STICKY_REVERT_DELAY 1000    /* Delay before sticky tooltips revert to normal */
 #define GTK_TOOLTIPS_GET_PRIVATE(obj) (G_TYPE_INSTANCE_GET_PRIVATE ((obj), GTK_TYPE_TOOLTIPS, GtkTooltipsPrivate))
 
 typedef struct _GtkTooltipsPrivate GtkTooltipsPrivate;
