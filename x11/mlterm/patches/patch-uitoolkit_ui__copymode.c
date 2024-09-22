$NetBSD: patch-uitoolkit_ui__copymode.c,v 1.1 2024/09/22 21:40:33 tsutsui Exp $

- pull upstream fixes to support backward search
  https://github.com/arakiken/mlterm/commit/64552b10
  > * ui_copymode.[ch], ui_screen.c:
  >   Pressing '?' in copy mode searchs for a string backward.
- pull additional upstream fix of search
  https://github.com/arakiken/mlterm/commit/0af65caa
  > * uitoolkit/ui_copymode.c: Replace the first character of input text
  >   by '/' or '?' in starting the copy mode every time.

--- uitoolkit/ui_copymode.c.orig	2023-04-01 13:54:40.000000000 +0000
+++ uitoolkit/ui_copymode.c
@@ -41,12 +41,12 @@ void ui_copymode_destroy(ui_copymode_t *
   free(copymode);
 }
 
-void ui_copymode_pattern_start_edit(ui_copymode_t *copymode) {
-  copymode->pattern_editing = 1;
+void ui_copymode_pattern_start_edit(ui_copymode_t *copymode, int backward) {
+  copymode->pattern_editing = backward ? 2 : 1;
   if (copymode->pattern_len == 0) {
     copymode->pattern_len = 1;
-    add_char_to_pattern(copymode->pattern, '/', US_ASCII, 0);
   }
+  add_char_to_pattern(copymode->pattern, backward ? '?' : '/', US_ASCII, 0);
 }
 
 void ui_copymode_pattern_cancel_edit(ui_copymode_t *copymode) {
