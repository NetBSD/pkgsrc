$NetBSD: patch-lib_libxview_ttysw_tty__menu.c,v 1.1 2012/11/16 00:29:40 joerg Exp $

--- lib/libxview/ttysw/tty_menu.c.orig	2012-11-14 16:02:26.000000000 +0000
+++ lib/libxview/ttysw/tty_menu.c
@@ -67,8 +67,8 @@ static void     ttysw_disable_scrolling(
 static void     ttysw_menu_page();
 static void     ttysw_menu_copy();
 static void     ttysw_menu_paste();
-/* static */ int ttysw_enable_editor();
-/* static */ int ttysw_disable_editor();
+/* static */ void ttysw_enable_editor();
+/* static */ void ttysw_disable_editor();
 /* static */ int ttysw_mode_action();
 /* static */ void
 	fit_termsw_panel_and_textsw(); /* BUG ALERT: No XView prefix */
@@ -684,7 +684,7 @@ fit_termsw_panel_and_textsw(frame, terms
 }
 
 /*ARGSUSED*/
-/* static */ int
+/* static */ void
 ttysw_enable_editor(cmd_menu, cmd_item)
     Menu            cmd_menu;
     Menu_item       cmd_item;
@@ -794,7 +794,7 @@ Press \"Continue\" to proceed."),
 
 
 /* ARGSUSED */
-/* static */ int
+/* static */ void
 ttysw_disable_editor(cmd_menu, cmd_item)
     Menu            cmd_menu;
     Menu_item       cmd_item;
