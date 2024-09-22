$NetBSD: patch-uitoolkit_ui__copymode.h,v 1.1 2024/09/22 21:40:33 tsutsui Exp $

- pull upstream fixes to support backward search
  https://github.com/arakiken/mlterm/commit/64552b10
  > * ui_copymode.[ch], ui_screen.c:
  >   Pressing '?' in copy mode searchs for a string backward.

--- uitoolkit/ui_copymode.h.orig	2023-04-01 13:54:40.000000000 +0000
+++ uitoolkit/ui_copymode.h
@@ -9,7 +9,7 @@
 typedef struct ui_copymode {
   vt_char_t pattern[MAX_COPYMODE_PATTERN_LEN];
   u_int8_t pattern_len;
-  int8_t pattern_editing;
+  int8_t pattern_editing; /* 2: backward, 1: forward */
 
   int16_t cursor_char_index; /* visual */
   int16_t cursor_row;        /* visual */
@@ -20,7 +20,7 @@ ui_copymode_t *ui_copymode_new(int char_
 
 void ui_copymode_destroy(ui_copymode_t *copymode);
 
-void ui_copymode_pattern_start_edit(ui_copymode_t *copymode);
+void ui_copymode_pattern_start_edit(ui_copymode_t *copymode, int backward);
 
 void ui_copymode_pattern_cancel_edit(ui_copymode_t *copymode);
 
