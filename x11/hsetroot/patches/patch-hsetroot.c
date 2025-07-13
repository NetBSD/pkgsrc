$NetBSD: patch-hsetroot.c,v 1.1 2025/07/13 15:13:34 vins Exp $

* Fix atom name used when clearing previous background.
* Introduce "sane" image rendering mode (from FreeBSD ports).

--- hsetroot.c.orig	2025-07-13 12:57:50.284721804 +0000
+++ hsetroot.c
@@ -8,7 +8,7 @@
 #include <string.h>
 
 
-typedef enum { Full, Fill, Center, Tile, Xtend, Cover } ImageMode;
+typedef enum { Full, Fill, Center, Tile, Xtend, Cover, Sane } ImageMode;
 
 void
 usage(char *commandline)
@@ -34,6 +34,7 @@ usage(char *commandline)
     "Image files:\n"
     " -center <image>            Render an image centered on screen\n"
     " -cover <image>             Render an image centered on screen scaled to fill the screen fully\n"
+    " -sane <image>              Render an image in sane mode (choose the best aspect, but do not center)\n"
     " -tile <image>              Render an image tiled\n"
     " -full <image>              Render an image maximum aspect\n"
     " -extend <image>            Render an image max aspect and fill borders\n"
@@ -134,7 +135,7 @@ parse_color(char *arg, Color *c, int def
 int
 load_image(ImageMode mode, const char *arg, int alpha, Imlib_Image rootimg, XineramaScreenInfo *outputs, int noutputs)
 {
-  int imgW, imgH, o;
+  int i, imgW, imgH, o;
   Imlib_Image buffer = imlib_load_image(arg);
 
   if (!buffer)
@@ -162,7 +163,7 @@ load_image(ImageMode mode, const char *a
 
   imlib_context_set_image(rootimg);
 
-  for (int i = 0; i < noutputs; i++) {
+  for (i = 0; i < noutputs; i++) {
     XineramaScreenInfo o = outputs[i];
     printf("output %d: size(%d, %d) pos(%d, %d)\n", i, o.width, o.height, o.x_org, o.y_org);
 
@@ -198,6 +199,20 @@ load_image(ImageMode mode, const char *a
           }
         }
       }
+    } else if (mode == Sane) {
+      int newW, newH;
+      double aspect_w = ((double) o.width) / imgW;
+      double aspect_h = ((double) o.height) / imgH;
+      if (aspect_h < aspect_w) {
+        // image is taller
+        newW = o.width;
+        newH = (int) (imgH * aspect_w);
+      } else {
+        // image is wider
+        newW = (int) (imgW * aspect_h);
+        newH = o.height;
+      }
+      imlib_blend_image_onto_image(buffer, 0, 0, 0, imgW, imgH, 0, 0, newW, newH);
     } else {  // Center || Tile
       int left = (o.width - imgW) / 2;
       int top = (o.height - imgH) / 2;
@@ -452,6 +467,15 @@ main(int argc, char **argv)
           fprintf (stderr, "Bad image (%s)\n", argv[i]);
           continue;
         }
+      } else if (strcmp (argv[i], "-sane") == 0) {
+        if ((++i) >= argc) {
+          fprintf(stderr, "Missing image\n");
+          continue;
+        }
+        if (load_image(Sane, argv[i], alpha, image, outputs, noutputs) == 0) {
+          fprintf(stderr, "Bad image (%s)\n", argv[i]);
+          continue;
+        }
       } else if (strcmp(argv[i], "-tint") == 0) {
         Color c;
         DATA8 r[256], g[256], b[256], a[256];
