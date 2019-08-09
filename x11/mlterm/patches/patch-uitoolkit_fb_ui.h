$ NetBSD $

- Fix support for fbi_fboffset != 0

Reported upstream:
https://bitbucket.org/arakiken/mlterm/pull-requests/5/fix-for-wscons-framebuffer/diff

--- uitoolkit/fb/ui.h.orig	2019-07-24 10:51:04.187713603 +0900
+++ uitoolkit/fb/ui.h	2019-07-24 09:59:19.091595937 +0900
@@ -44,6 +44,7 @@ typedef struct {
 
   int fb_fd;
   unsigned char *fb;
+  unsigned char *fb_base;
   size_t smem_len;
   unsigned int line_length;
   unsigned int xoffset;
