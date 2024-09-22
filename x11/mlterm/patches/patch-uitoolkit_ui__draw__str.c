$NetBSD: patch-uitoolkit_ui__draw__str.c,v 1.1 2024/09/22 21:40:33 tsutsui Exp $

- pull upstream transparent fixes:
  https://github.com/arakiken/mlterm/commit/51232032
  > * ui_imagelib.h, */ui_imagelib.c: Add 'transparent' to arguments of
  >   ui_imagelib_load_file().
  > * c_sixel.c: load_sixel_from_{data|file}() check whether P2 is 1 or not
  >   and return it by 'transparent' argument.
- pull additional upstream transparent fixes:
  https://github.com/arakiken/mlterm/commit/92fa70f1
  > * ui_draw_str.c: Add 'int draw_bg' to arguments of draw_picture().
  > * vt_parser.c: show_picture() calls interrupt_vt100_cmd() if
  >   vt_screen_line_feed() returns 2.
  > * vt_edit.c: vt_edit_go_downward() returns 2 if screen scrolling occurs.

--- uitoolkit/ui_draw_str.c.orig	2023-04-01 13:54:40.000000000 +0000
+++ uitoolkit/ui_draw_str.c
@@ -111,8 +111,17 @@ static void draw_line(ui_window_t *windo
 #endif
 
 #ifndef NO_IMAGE
+void draw_background(ui_window_t *win, ui_color_t *color, int x, int y, u_int width, u_int height) {
+  if (!color) {
+    ui_window_clear(win, x, y, width, height);
+  } else {
+    ui_window_fill_with(win, color, x, y, width, height);
+  }
+}
+
 static int draw_picture(ui_window_t *window, u_int32_t *glyphs, u_int num_glyphs, int dst_x,
-                        int dst_y, u_int ch_width, u_int line_height, ui_color_t *bg_xcolor) {
+                        int dst_y, u_int ch_width, u_int line_height, ui_color_t *bg_xcolor,
+                        int draw_bg) {
   u_int count;
   ui_inline_picture_t *cur_pic;
   u_int num_rows;
@@ -161,12 +170,8 @@ static int draw_picture(ui_window_t *win
     if (count == 0) {
       goto new_picture;
     } else if (w > 0 && pic == cur_pic && src_x + src_width == x) {
-      if (!need_clear && w < ch_width) {
-        if (!bg_xcolor) {
-          ui_window_clear(window, dst_x + dst_width, dst_y, ch_width, line_height);
-        } else {
-          ui_window_fill_with(window, bg_xcolor, dst_x + dst_width, dst_y, ch_width, line_height);
-        }
+      if (draw_bg && !cur_pic->transparent && !need_clear && w < ch_width) {
+        draw_background(window, bg_xcolor, dst_x + dst_width, dst_y, ch_width, line_height);
       }
 
       src_width += w;
@@ -180,11 +185,8 @@ static int draw_picture(ui_window_t *win
     }
 
     if (need_clear > 0) {
-      if (!bg_xcolor) {
-        ui_window_clear(window, dst_x, dst_y, dst_width, line_height);
-      } else {
-        ui_window_fill_with(window, bg_xcolor, dst_x, dst_y, dst_width, line_height);
-      }
+      /* cur_pic->transparent is always false. */
+      draw_background(window, bg_xcolor, dst_x, dst_y, dst_width, line_height);
     }
 
     if (src_width > 0 && src_height > 0
@@ -214,10 +216,6 @@ static int draw_picture(ui_window_t *win
     cur_pic = pic;
     need_clear = 0;
 
-    if (cur_pic->mask) {
-      need_clear = 1;
-    }
-
     if (src_y + line_height > pic->height) {
       need_clear = 1;
       src_height = pic->height > src_y ? pic->height - src_y : 0;
@@ -225,38 +223,41 @@ static int draw_picture(ui_window_t *win
       src_height = line_height;
     }
 
-    if (strstr(cur_pic->file_path, "mlterm/animx") && cur_pic->next_frame >= 0) {
-      /* Don't clear if cur_pic is 2nd or later GIF Animation frame. */
-      need_clear = -1;
-    }
+    src_width = w;
 
-    if ((src_width = w) < ch_width && !need_clear) {
-      if (!bg_xcolor) {
-        ui_window_clear(window, dst_x, dst_y, ch_width, line_height);
-      } else {
-        ui_window_fill_with(window, bg_xcolor, dst_x, dst_y, ch_width, line_height);
+    if (draw_bg && !cur_pic->transparent) {
+      if (cur_pic->mask) {
+        need_clear = 1;
       }
-    }
-  }
 
-  if (need_clear > 0) {
-    if (!bg_xcolor) {
-      ui_window_clear(window, dst_x, dst_y, dst_width, line_height);
+      if (strstr(cur_pic->file_path, "mlterm/animx") && cur_pic->next_frame >= 0) {
+        /* Don't clear if cur_pic is 2nd or later GIF Animation frame. */
+        need_clear = -1;
+      }
+
+      if (src_width < ch_width && !need_clear) {
+        draw_background(window, bg_xcolor, dst_x, dst_y, ch_width, line_height);
+      }
     } else {
-      ui_window_fill_with(window, bg_xcolor, dst_x, dst_y, dst_width, line_height);
+      need_clear = 0;
     }
   }
 
-#ifdef __DEBUG
-  bl_debug_printf("Drawing picture at %d %d (pix %p mask %p x %d y %d w %d h %d)\n", dst_x, dst_y,
-                  cur_pic->pixmap, cur_pic->mask, src_x, src_y, src_width, src_height);
-#endif
+  if (need_clear > 0) {
+    /* cur_pic->transparent is always false. */
+    draw_background(window, bg_xcolor, dst_x, dst_y, dst_width, line_height);
+  }
 
   if (src_width > 0 && src_height > 0
 #ifndef INLINE_PICTURE_MOVABLE_BETWEEN_DISPLAYS
       && cur_pic->disp == window->disp
 #endif
       ) {
+#ifdef __DEBUG
+    bl_debug_printf("*Drawing picture at %d %d (pix %p mask %p x %d y %d w %d h %d)\n", dst_x,
+                    dst_y, cur_pic->pixmap, cur_pic->mask, src_x, src_y, src_width, src_height);
+#endif
+
     ui_window_copy_area(window, cur_pic->pixmap, cur_pic->mask, src_x, src_y, src_width, src_height,
                         dst_x, dst_y);
   }
@@ -657,17 +658,17 @@ static int fc_draw_str(ui_window_t *wind
       draw_count++;
 #endif
 
-      bg_xcolor = ui_get_xcolor(color_man, bg_color);
-
 #ifndef NO_IMAGE
       if (state == 4) {
         draw_picture(window, pic_glyphs, str_len, x, y, ch_width, height,
-                     bg_color == VT_BG_COLOR ? NULL : bg_xcolor);
+                     bg_color == VT_BG_COLOR ? NULL : ui_get_xcolor(color_man, bg_color),
+                     updated_width ? 1 : 0);
 
         goto end_draw;
       }
 #endif
 
+      bg_xcolor = ui_get_xcolor(color_man, bg_color);
       fg_xcolor = ui_get_xcolor(color_man, fg_color);
 
       /*
@@ -1020,6 +1021,16 @@ static int xcore_draw_str(ui_window_t *w
       draw_count++;
 #endif
 
+#ifndef NO_IMAGE
+      if (state == 4) {
+        draw_picture(window, pic_glyphs, str_len, x, y, ch_width, height,
+                     bg_color == VT_BG_COLOR ? NULL : ui_get_xcolor(color_man, bg_color),
+                     updated_width ? 1 : 0);
+
+        goto end_draw;
+      }
+#endif
+
 #ifdef DRAW_SCREEN_IN_PIXELS
       if (ui_window_has_wall_picture(window) && bg_color == VT_BG_COLOR) {
         bg_xcolor = NULL;
@@ -1029,15 +1040,6 @@ static int xcore_draw_str(ui_window_t *w
         bg_xcolor = ui_get_xcolor(color_man, bg_color);
       }
 
-#ifndef NO_IMAGE
-      if (state == 4) {
-        draw_picture(window, pic_glyphs, str_len, x, y, ch_width, height,
-                     bg_color == VT_BG_COLOR ? NULL : bg_xcolor);
-
-        goto end_draw;
-      }
-#endif
-
       fg_xcolor = ui_get_xcolor(color_man, fg_color);
 
 #ifdef USE_CONSOLE
