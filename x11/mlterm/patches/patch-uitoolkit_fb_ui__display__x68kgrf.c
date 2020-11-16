$NetBSD: patch-uitoolkit_fb_ui__display__x68kgrf.c,v 1.4 2020/11/16 11:58:09 tsutsui Exp $

- Add support of X68030 CRT Mode 19 (640x480x4) for mlterm-x68kgrf.
 https://github.com/arakiken/mlterm/commit/0d3a3b0bdc36ee2d702167fd234dcfc3c500ac09

--- uitoolkit/fb/ui_display_x68kgrf.c.orig	2020-11-08 12:57:31.000000000 +0000
+++ uitoolkit/fb/ui_display_x68kgrf.c
@@ -153,6 +153,8 @@ static int open_display(u_int depth) {
                                   {4, 0x24e4 /* Graphic vram is prior to text one. */, 0x0010}};
   fb_reg_conf_t conf_1024_768_4 = {{169, 14, 28, 156, 439, 5, 40, 424, 27, 1050},
                                    {4, 0x24e4 /* Graphic vram is prior to text one. */, 0x0010}};
+  fb_reg_conf_t conf_640_480_4 = {{99, 11, 13, 93, 524, 1, 33, 513, 27, 1047},
+                                   {4, 0x24e4 /* Graphic vram is prior to text one. */, 0x0010}};
   struct rgb_info rgb_info_15bpp = {3, 3, 3, 6, 11, 1};
   struct termios tm;
 
@@ -214,7 +216,11 @@ static int open_display(u_int depth) {
                   orig_reg.crtc.r08, orig_reg.crtc.r20, orig_reg.videoc.r0, orig_reg.videoc.r1,
                   orig_reg.videoc.r2);
 #else
-  orig_reg = conf_768_512_4;
+  if (vinfo.gd_dwidth == 640) {
+    orig_reg = conf_640_480_4;
+  } else {
+    orig_reg = conf_768_512_4;
+  }
   orig_reg.videoc.r2 = 0x20;
 #endif
 
@@ -240,6 +246,11 @@ static int open_display(u_int depth) {
 
         _display.width = _disp.width = 1024;
         _display.height = _disp.height = 768;
+      } else if (fb_width == 640 && fb_height == 480) {
+        conf = &conf_640_480_4;
+
+        _display.width = _disp.width = 640;
+        _display.height = _disp.height = 480;
       } else {
         conf = &conf_768_512_4;
 
