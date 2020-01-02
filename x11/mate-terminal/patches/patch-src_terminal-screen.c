$NetBSD: patch-src_terminal-screen.c,v 1.1 2020/01/02 18:55:58 gutteridge Exp $

Avoid NULL pointer dereference in terminal_screen_child_exited.
https://github.com/mate-desktop/mate-terminal/commit/fe73da93aa0a14ee471e7a6af7914197c41d3723

--- src/terminal-screen.c.orig	2019-04-23 10:25:08.000000000 +0000
+++ src/terminal-screen.c
@@ -1946,6 +1946,9 @@ terminal_screen_child_exited (VteTermina
 		break;
 	case TERMINAL_EXIT_HOLD:
 	{
+		if ((status == 9) && (priv->override_command == NULL))
+			break;
+
 		GtkWidget *info_bar;
 
 		info_bar = terminal_info_bar_new (GTK_MESSAGE_INFO,
