$ NetBSD $

- Fix support for fbi_fboffset != 0

Reported upstream:
https://bitbucket.org/arakiken/mlterm/pull-requests/5/fix-for-wscons-framebuffer/diff

--- uitoolkit/fb/ui_display_linux.c.orig	2019-07-24 10:51:04.215385175 +0900
+++ uitoolkit/fb/ui_display_linux.c	2019-07-24 09:59:19.092709670 +0900
@@ -265,7 +265,7 @@ static int open_display(u_int depth) {
     _display.pixels_per_byte = 1;
   }
 
-  if ((_display.fb = mmap(NULL, (_display.smem_len = finfo.smem_len), PROT_WRITE | PROT_READ,
+  if ((_display.fb = _display.fb_base = mmap(NULL, (_display.smem_len = finfo.smem_len), PROT_WRITE | PROT_READ,
                           MAP_SHARED, _display.fb_fd, (off_t)0)) == MAP_FAILED) {
     goto error;
   }
@@ -349,7 +349,7 @@ static int open_display(u_int depth) {
 error:
   if (_display.fb) {
     munmap(_display.fb, _display.smem_len);
-    _display.fb = NULL;
+    _display.fb = _display.fb_base = NULL;
   }
 
   close(_display.fb_fd);
