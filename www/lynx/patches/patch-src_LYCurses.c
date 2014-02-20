$NetBSD: patch-src_LYCurses.c,v 1.1 2014/02/20 10:07:35 wiz Exp $

Fix build without keymaps support.

--- src/LYCurses.c.orig	2013-11-29 00:52:56.000000000 +0000
+++ src/LYCurses.c
@@ -1180,10 +1180,12 @@ void restart_curses(void)
     keypad(LYwin, TRUE);
     lynx_enable_mouse(1);
 
+#if defined(USE_KEYMAPS)  
     if (-1 == lynx_initialize_keymaps()) {
 	endwin();
 	exit_immediately(EXIT_FAILURE);
     }
+#endif
     if (has_colors()) {
 	start_color();
     }
