$ NetBSD $

- Fix support for fbi_fboffset != 0

Reported upstream:
https://bitbucket.org/arakiken/mlterm/pull-requests/5/fix-for-wscons-framebuffer/diff

--- uitoolkit/fb/ui_display_freebsd.c.orig	2019-07-24 10:51:04.208029557 +0900
+++ uitoolkit/fb/ui_display_freebsd.c	2019-07-24 10:37:10.728676339 +0900
@@ -64,7 +64,7 @@ static int open_display(u_int depth) {
   ioctl(_display.fb_fd, FBIO_ADPINFO, &vainfo);
   ioctl(_display.fb_fd, FBIO_GETDISPSTART, &vstart);
 
-  if ((_display.fb = mmap(NULL, (_display.smem_len = vainfo.va_window_size), PROT_WRITE | PROT_READ,
+  if ((_display.fb = _display.fb_base = mmap(NULL, (_display.smem_len = vainfo.va_window_size), PROT_WRITE | PROT_READ,
                           MAP_SHARED, _display.fb_fd, (off_t)0)) == MAP_FAILED) {
     bl_error_printf("Retry another mode of resolution and depth.\n");
 
@@ -209,7 +209,7 @@ static int open_display(u_int depth) {
 error:
   if (_display.fb) {
     munmap(_display.fb, _display.smem_len);
-    _display.fb = NULL;
+    _display.fb = _display.fb_base = NULL;
   }
 
   close(_display.fb_fd);
