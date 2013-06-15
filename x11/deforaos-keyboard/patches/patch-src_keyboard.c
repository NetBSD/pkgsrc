$NetBSD: patch-src_keyboard.c,v 1.1 2013/06/15 12:27:47 khorben Exp $

API change in libDesktop 0.0.10

--- src/keyboard.c.orig	2012-09-22 01:07:48.000000000 +0000
+++ src/keyboard.c
@@ -437,8 +437,8 @@ Keyboard * keyboard_new(KeyboardPrefs * 
 	keyboard_set_layout(keyboard, KLS_LETTERS);
 	pango_font_description_free(bold);
 	/* messages */
-	desktop_message_register(KEYBOARD_CLIENT_MESSAGE, on_keyboard_message,
-			keyboard);
+	desktop_message_register(keyboard->window, KEYBOARD_CLIENT_MESSAGE,
+			on_keyboard_message, keyboard);
 	return keyboard;
 }
 
