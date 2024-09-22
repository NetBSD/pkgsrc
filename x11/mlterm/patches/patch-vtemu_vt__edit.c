$NetBSD: patch-vtemu_vt__edit.c,v 1.1 2024/09/22 21:40:33 tsutsui Exp $

- pull additional upstream transparent fixes:
  https://github.com/arakiken/mlterm/commit/92fa70f1
  > * ui_draw_str.c: Add 'int draw_bg' to arguments of draw_picture().
  > * vt_parser.c: show_picture() calls interrupt_vt100_cmd() if
  >   vt_screen_line_feed() returns 2.
  > * vt_edit.c: vt_edit_go_downward() returns 2 if screen scrolling occurs.

--- vtemu/vt_edit.c.orig	2023-04-01 13:54:40.000000000 +0000
+++ vtemu/vt_edit.c
@@ -2064,17 +2064,23 @@ int vt_edit_go_downward(vt_edit_t *edit,
 
       return 0;
     }
+
+#ifdef CURSOR_DEBUG
+    vt_cursor_dump(&edit->cursor);
+#endif
+
+    return 2; /* scrolled */
   } else {
     if (!vt_cursor_goto_by_col(&edit->cursor, edit->cursor.col, edit->cursor.row + 1)) {
       return 0;
     }
-  }
 
 #ifdef CURSOR_DEBUG
-  vt_cursor_dump(&edit->cursor);
+    vt_cursor_dump(&edit->cursor);
 #endif
 
-  return 1;
+    return 1;
+  }
 }
 
 int vt_edit_goto(vt_edit_t *edit, int col, int row) {
