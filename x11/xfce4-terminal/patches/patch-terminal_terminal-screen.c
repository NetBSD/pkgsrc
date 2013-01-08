$NetBSD: patch-terminal_terminal-screen.c,v 1.1 2013/01/08 01:23:19 marino Exp $

Fix for 100% CPU usage on XFce4 Terminal (Dave Tyson)
PR# pkg/45448
PR# pkg/46926

--- terminal/terminal-screen.c.orig	2009-10-06 15:07:01.000000000 +0000
+++ terminal/terminal-screen.c
@@ -87,6 +87,7 @@ static gboolean   terminal_screen_get_ch
                                                                  GError               **error);
 static gchar    **terminal_screen_get_child_environment         (TerminalScreen        *screen);
 static void       terminal_screen_update_background             (TerminalScreen        *screen);
+static void       terminal_screen_update_background_fast        (TerminalScreen        *screen);
 static void       terminal_screen_update_binding_backspace      (TerminalScreen        *screen);
 static void       terminal_screen_update_binding_delete         (TerminalScreen        *screen);
 static void       terminal_screen_update_colors                 (TerminalScreen        *screen);
@@ -132,6 +133,8 @@ struct _TerminalScreen
   GtkWidget           *scrollbar;
   GtkWidget           *tab_label;
 
+  gulong              background_signal_id;
+
   GPid                 pid;
   gchar               *working_directory;
 
@@ -231,7 +234,6 @@ terminal_screen_init (TerminalScreen *sc
                     "signal::context-menu", G_CALLBACK (terminal_screen_vte_get_context_menu), screen,
                     "signal::selection-changed", G_CALLBACK (terminal_screen_vte_selection_changed), screen,
                     "signal::window-title-changed", G_CALLBACK (terminal_screen_vte_window_title_changed), screen,
-                    "swapped-signal::size-allocate", G_CALLBACK (terminal_screen_timer_background), screen,
                     "swapped-signal::style-set", G_CALLBACK (terminal_screen_update_colors), screen,
                     NULL);
   gtk_box_pack_start (GTK_BOX (screen), screen->terminal, TRUE, TRUE, 0);
@@ -573,6 +575,18 @@ terminal_screen_get_child_environment (T
 
 
 static void
+terminal_screen_update_background_fast (TerminalScreen *screen)
+{
+  if (G_UNLIKELY (screen->background_timer_id == 0))
+    {
+      screen->background_timer_id = g_idle_add_full (G_PRIORITY_LOW, terminal_screen_timer_background,
+                                                     screen, terminal_screen_timer_background_destroy);
+    }
+}
+
+
+
+static void
 terminal_screen_update_background (TerminalScreen *screen)
 {
   if (G_UNLIKELY (screen->background_timer_id != 0))
@@ -1015,9 +1029,25 @@ terminal_screen_timer_background (gpoint
       if (G_LIKELY (image != NULL))
         g_object_unref (G_OBJECT (image));
       g_object_unref (G_OBJECT (loader));
+      
+            /* refresh background on size changes */
+            if (screen->background_signal_id == 0)
+              {
+                screen->background_signal_id =
+                   g_signal_connect_swapped (G_OBJECT (screen->terminal), "size-allocate",
+                                             G_CALLBACK (terminal_screen_update_background_fast), screen);
+              }
     }
   else
     {
+          /* stop updating on size changes */
+          if (screen->background_signal_id != 0)
+            {
+              g_signal_handler_disconnect (G_OBJECT (screen->terminal), screen->background_signal_id);
+              screen->background_signal_id = 0;
+            }
+    
+          /* WARNING: the causes a resize too! */
       vte_terminal_set_background_image (VTE_TERMINAL (screen->terminal), NULL);
     }
 
