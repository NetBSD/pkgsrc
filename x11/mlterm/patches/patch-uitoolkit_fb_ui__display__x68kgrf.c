$ NetBSD $

- Fix support for fbi_fboffset != 0

Reported upstream:
https://bitbucket.org/arakiken/mlterm/pull-requests/5/fix-for-wscons-framebuffer/diff

--- uitoolkit/fb/ui_display_x68kgrf.c.orig	2019-07-24 10:51:04.212502056 +0900
+++ uitoolkit/fb/ui_display_x68kgrf.c	2019-07-24 10:01:35.627124287 +0900
@@ -173,7 +173,7 @@ static int open_display(u_int depth) {
 
   _display.smem_len = vinfo.gd_fbsize + vinfo.gd_regsize;
 
-  if ((_display.fb = mmap(NULL, _display.smem_len, PROT_WRITE | PROT_READ, MAP_FILE | MAP_SHARED,
+  if ((_display.fb = _display.fb_base = mmap(NULL, _display.smem_len, PROT_WRITE | PROT_READ, MAP_FILE | MAP_SHARED,
                           _display.fb_fd, (off_t)0)) == MAP_FAILED) {
     bl_error_printf("Retry another mode of resolution and depth.\n");
 
@@ -339,7 +339,7 @@ error:
   if (_display.fb) {
     setup_reg(reg, &orig_reg);
     munmap(_display.fb, _display.smem_len);
-    _display.fb = NULL;
+    _display.fb = _display.fb_base = NULL;
   }
 
   close(_display.fb_fd);
