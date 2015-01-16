$NetBSD: patch-widget_gtk_gtk3drawing.c,v 1.2 2015/01/16 22:42:09 ryoon Exp $

--- widget/gtk/gtk3drawing.c.orig	2015-01-09 04:38:28.000000000 +0000
+++ widget/gtk/gtk3drawing.c
@@ -64,6 +64,7 @@ static GtkWidget* gScrolledWindowWidget;
 
 static style_prop_t style_prop_func;
 static gboolean have_arrow_scaling;
+static gboolean checkbox_check_state;
 static gboolean is_initialized;
 
 #define ARROW_UP      0
@@ -71,6 +72,10 @@ static gboolean is_initialized;
 #define ARROW_RIGHT   G_PI_2
 #define ARROW_LEFT    (G_PI+G_PI_2)
 
+#if !GTK_CHECK_VERSION(3,14,0)
+#define GTK_STATE_FLAG_CHECKED (1 << 11)
+#endif
+
 static GtkStateFlags
 GetStateFlagsFromGtkWidgetState(GtkWidgetState* state)
 {
@@ -714,6 +719,11 @@ moz_gtk_init()
     is_initialized = TRUE;
     have_arrow_scaling = (gtk_major_version > 2 ||
                           (gtk_major_version == 2 && gtk_minor_version >= 12));
+    if (gtk_major_version > 3 ||
+       (gtk_major_version == 3 && gtk_minor_version >= 14))
+        checkbox_check_state = GTK_STATE_FLAG_CHECKED;
+    else
+        checkbox_check_state = GTK_STATE_FLAG_ACTIVE;
 
     /* Add style property to GtkEntry.
      * Adding the style property to the normal GtkEntry class means that it
@@ -1004,10 +1014,10 @@ moz_gtk_toggle_paint(cairo_t *cr, GdkRec
     gtk_widget_set_sensitive(w, !state->disabled);
     gtk_widget_set_direction(w, direction);
     gtk_style_context_save(style);
-      
+
     if (isradio) {
         gtk_style_context_add_class(style, GTK_STYLE_CLASS_RADIO);
-        gtk_style_context_set_state(style, selected ? GTK_STATE_FLAG_ACTIVE :
+        gtk_style_context_set_state(style, selected ? checkbox_check_state :
                                                       GTK_STATE_FLAG_NORMAL);
         gtk_render_option(style, cr, x, y, width, height);
         if (state->focused) {
@@ -1025,7 +1035,7 @@ moz_gtk_toggle_paint(cairo_t *cr, GdkRec
             gtk_style_context_set_state(style, GTK_STATE_FLAG_INCONSISTENT);
             gtk_toggle_button_set_inconsistent(GTK_TOGGLE_BUTTON(gCheckboxWidget), TRUE);
         } else if (selected) {
-            gtk_style_context_set_state(style, GTK_STATE_FLAG_ACTIVE);
+            gtk_style_context_set_state(style, checkbox_check_state);
         } else {
             gtk_toggle_button_set_inconsistent(GTK_TOGGLE_BUTTON(gCheckboxWidget), FALSE);
         }
@@ -2588,8 +2598,9 @@ moz_gtk_check_menu_item_paint(cairo_t *c
       gtk_style_context_add_class(style, GTK_STYLE_CLASS_CHECK);
     }
 
-    if (checked)
-      state_flags |= GTK_STATE_FLAG_ACTIVE;
+    if (checked) {
+      state_flags |= checkbox_check_state;
+    }
     
     gtk_style_context_set_state(style, state_flags);
     gtk_style_context_get_padding(style, state_flags, &padding);
