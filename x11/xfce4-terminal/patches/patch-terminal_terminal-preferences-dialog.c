$NetBSD: patch-terminal_terminal-preferences-dialog.c,v 1.1 2024/02/23 20:38:49 gutteridge Exp $

Fix regression with pasting multi-line data.
https://gitlab.xfce.org/apps/xfce4-terminal/-/commit/71ecd2a721b059394edcfb316a20ac9d46a7b2cd

--- terminal/terminal-preferences-dialog.c.orig	2024-01-23 19:10:59.000000000 +0000
+++ terminal/terminal-preferences-dialog.c
@@ -1893,7 +1893,7 @@ terminal_preferences_dialog_presets_chan
   GValue        src = { 0, };
   GValue        dst = { 0, };
 
-  g_return_if_fail (TERMINAL_IS_PREFERENCES_DIALOG (widget));
+  g_return_if_fail (TERMINAL_IS_PREFERENCES_DIALOG (dialog));
   g_return_if_fail (GTK_IS_COMBO_BOX (widget));
 
   combobox = GTK_COMBO_BOX (widget);
