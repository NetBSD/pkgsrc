$NetBSD: patch-xglock_xglock.c,v 1.1 2026/06/24 22:06:09 wiz Exp $

The prototypes don't match the functions; remove them instead of fixing them.

--- xglock/xglock.c.orig	2026-06-24 22:01:40.350287572 +0000
+++ xglock/xglock.c
@@ -105,55 +105,7 @@ static GtkTooltips *tooltips=(GtkTooltips *)NULL;
 /*static GtkWidget *font_sel_entry =(GtkWidget *)NULL;*/
 static GtkTooltips *tooltips=(GtkTooltips *)NULL;
 
-/* Prototypes */
-#if defined( __ANSI_C__ ) || defined( NeedFunctionsPrototypes )
-# define __PROTO( name, args )  name args
-#else /* ! __ANSI_C__ && ! NeedFunctionsPrototypes */
-# define __PROTO( name, args )  name ()
-#endif /* ? __ANSI_C__ && ! NeedFunctionsPrototypes */
-
 #define STD_CB_ARGS	(GtkWidget *, gpointer)
-
-static void *__PROTO( secured_malloc, (size_t) );
-static void *__PROTO( secured_calloc, (int, size_t) );
-static void *__PROTO( secured_realloc, (void *, size_t) );
-static gchar *__PROTO( check_quotes, (gchar *str) );
-
-static void __PROTO( mode_list_item_select_cb, STD_CB_ARGS );
-static void __PROTO( mode_list_item_unselect_cb, STD_CB_ARGS );
-static void __PROTO( compose_xlock_command, (char *) );
-static void __PROTO( kill_xlock_cb, STD_CB_ARGS );
-static void __PROTO( launch_xlock, STD_CB_ARGS );
-static void __PROTO( exit_xglock, STD_CB_ARGS );
-static void __PROTO( bool_option_clicked_cb, STD_CB_ARGS );
-static void __PROTO( destroy_window, STD_CB_ARGS );
-
-static void __PROTO( color_selection_cancel_cb, STD_CB_ARGS );
-static void __PROTO( color_selection_ok_cb, STD_CB_ARGS );
-static void __PROTO( color_selection_changed_cb, STD_CB_ARGS );
-static void __PROTO( create_color_selection_dialog, STD_CB_ARGS );
-
-/*static void __PROTO( font_select_item_select_cb, STD_CB_ARGS );*/
-static void __PROTO( font_select_cancel_cb, STD_CB_ARGS );
-static void __PROTO( font_select_ok_cb, STD_CB_ARGS );
-static void __PROTO( create_font_selection_dialog, STD_CB_ARGS );
-
-static void __PROTO( file_selection_cancel_cb, STD_CB_ARGS );
-static void __PROTO( file_selection_ok_cb, STD_CB_ARGS );
-static void __PROTO( create_file_selection_dialog, STD_CB_ARGS );
-
-static void __PROTO( contextual_help_dialog, STD_CB_ARGS );
-static void __PROTO( window_help_dialog, STD_CB_ARGS );
-static void __PROTO( global_help_dialog, STD_CB_ARGS );
-static void __PROTO( about_dialog, STD_CB_ARGS );
-static void __PROTO( about_dialog_close_callback, STD_CB_ARGS );
-
-static GtkWidget * __PROTO( create_file_menu, (GtkWidget *) );
-static GtkWidget * __PROTO( create_help_menu, (GtkWidget *) );
-
-static void __PROTO( create_fntColorOptions_entries, (GtkWidget *) );
-static void __PROTO( create_genOptions_entries, (GtkWidget *) );
-static void __PROTO( create_boolOptions_buttons, (GtkWidget *) );
 
 #if GTK_CHECK_VERSION(2,0,0)
 /* GTK+ 2.x differences */
