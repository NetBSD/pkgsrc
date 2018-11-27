$NetBSD: patch-components_editor_gtkhtml-spell-checker.c,v 1.1 2018/11/27 20:32:06 bsiegert Exp $

Replace deprecated function (removed in enchant2).

--- components/editor/gtkhtml-spell-checker.c.orig	2010-09-13 12:16:10.000000000 +0000
+++ components/editor/gtkhtml-spell-checker.c
@@ -376,7 +376,7 @@ gtkhtml_spell_checker_add_word (GtkhtmlS
 	if ((dict = spell_checker_request_dict (checker)) == NULL)
 		return;
 
-	enchant_dict_add_to_pwl (dict, word, length);
+	enchant_dict_add (dict, word, length);
 	g_signal_emit (G_OBJECT (checker), signals[ADDED], 0, word, length);
 }
 
