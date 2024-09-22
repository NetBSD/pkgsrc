$NetBSD: patch-tool_mlimgloader_libpng.c,v 1.1 2024/09/22 21:40:32 tsutsui Exp $

- pull upstream fixes to use libpng if gdk-pixbuf is not used.
  https://github.com/arakiken/mlterm/commit/0af65caa
  > * README, doc/ja/README.ja: Updated.
  > * uitoolkit/ui_copymode.c: Replace the first character of input text
  >   by '/' or '?' in starting the copy mode every time.
  > * configure.in: Check libpng if gdk-pixbuf is not found.
  > * tool/mlimgloader/libpng.c, stb_image_resize2.h: Added.

--- tool/mlimgloader/libpng.c.orig	2024-09-22 17:39:12.062316686 +0000
+++ tool/mlimgloader/libpng.c
@@ -0,0 +1,190 @@
+/* -*- c-basic-offset:2; tab-width:2; indent-tabs-mode:nil -*- */
+
+#include <png.h>
+#include <pobl/bl_util.h> /* BL_MIN */
+#include <pobl/bl_types.h>
+#include <pobl/bl_mem.h>
+#include <unistd.h> /* read/write */
+#include <string.h> /* memset */
+
+#define USE_LIBPNG
+
+#define GDK_PIXBUF_VERSION
+#define GDK_PIXBUF_MAJOR 1
+
+#define TRUE 1
+#define FALSE 0
+
+typedef unsigned char guchar;
+typedef void * gpointer;
+typedef char gboolean;
+typedef u_int guint;
+typedef u_int32_t guint32;
+
+typedef enum {
+  GDK_COLORSPACE_RGB
+} GdkColorspace;
+
+typedef enum {
+  GDK_INTERP_NEAREST,
+  GDK_INTERP_TILES,
+  GDK_INTERP_BILINEAR,
+  GDK_INTERP_HYPER
+} GdkInterpType;
+
+typedef void (*GdkPixbufDestroyNotify)(guchar *pixels, gpointer data);
+
+typedef struct _GdkPixbuf {
+  guchar *data;
+  int width;
+  int height;
+  int stride;
+  int has_alpha;
+  int ref_count;
+  GdkPixbufDestroyNotify destroy;
+  gpointer destroy_data;
+
+} GdkPixbuf;
+
+#define STB_IMAGE_RESIZE_IMPLEMENTATION
+#include "stb_image_resize2.h"
+
+void gdk_pixbuf_ref(GdkPixbuf *pixbuf) {
+  pixbuf->ref_count++;
+}
+
+void gdk_pixbuf_unref(GdkPixbuf *pixbuf) {
+  if (--pixbuf->ref_count == 0) {
+    if (pixbuf->destroy) {
+      (*pixbuf->destroy)(pixbuf->data, pixbuf->destroy_data);
+    } else {
+      free(pixbuf->data);
+    }
+    free(pixbuf);
+  }
+}
+
+GdkPixbuf *gdk_pixbuf_new_from_data(const guchar *data,
+                                    GdkColorspace colorspace, /* support GDB_COLORSPACE_RGB alone */
+                                    gboolean has_alpha,
+                                    int bits_per_sample, /* support 8 bits alone */
+                                    int width, int height, int rowstride,
+                                    GdkPixbufDestroyNotify destroy_fn,
+                                    gpointer destroy_fn_data) {
+  GdkPixbuf *pixbuf;
+
+  if ((pixbuf = malloc(sizeof(GdkPixbuf)))) {
+    pixbuf->data = (guchar*)data;
+    pixbuf->width = width;
+    pixbuf->height = height;
+    pixbuf->stride = rowstride;
+    pixbuf->has_alpha = has_alpha;
+    pixbuf->destroy = destroy_fn;
+    pixbuf->destroy_data = destroy_fn_data;
+    pixbuf->ref_count = 1;
+  }
+
+  return pixbuf;
+}
+
+GdkPixbuf *gdk_pixbuf_new(GdkColorspace colorspace, gboolean has_alpha,
+                          int bits_per_sample, int width, int height) {
+  guchar *data;
+  int bytes_per_pixel = has_alpha ? 4 : 3;
+  int stride = width * bytes_per_pixel;
+
+  if (stride / bytes_per_pixel == width /* != width -> integer overflow */ &&
+      (data = calloc(stride, height))) {
+    return gdk_pixbuf_new_from_data(data, colorspace, has_alpha, bits_per_sample,
+                                    width, height, stride, NULL, NULL);
+  }
+
+  return NULL;
+}
+
+GdkPixbuf *gdk_pixbuf_new_from_file(const char *path) {
+  png_image png;
+  u_int32_t stride;
+  guchar *data;
+
+  memset(&png, 0, sizeof(png));
+  png.version = PNG_IMAGE_VERSION;
+
+  png_image_begin_read_from_file(&png, path);
+
+  if(PNG_IMAGE_FAILED(png)) {
+    return NULL;
+  }
+
+  png.format &= PNG_FORMAT_FLAG_ALPHA;
+  png.format |= PNG_FORMAT_FLAG_COLOR;
+  stride = PNG_IMAGE_ROW_STRIDE(png);
+
+  if ((data = malloc(PNG_IMAGE_BUFFER_SIZE(png, stride)))) {
+    png_image_finish_read(&png, NULL, data, stride, NULL);
+    png_image_free(&png);
+
+    return gdk_pixbuf_new_from_data(data, GDK_COLORSPACE_RGB,
+                                    (png.format & PNG_FORMAT_FLAG_ALPHA) ? TRUE : FALSE , 8,
+                                    png.width, png.height, stride, NULL, NULL);
+  } else {
+    png_image_free(&png);
+
+    return NULL;
+  }
+}
+
+void gdk_pixbuf_fill(GdkPixbuf *pixbuf, guint32 pixel) {
+  guint x, y;
+  guint32 *data = (guint32*)pixbuf->data;
+
+  for (y = 0; y < pixbuf->height; y++) {
+    for (x = 0; x < pixbuf->width; x++) {
+      *(data++) = pixel;
+    }
+  }
+}
+
+void gdk_pixbuf_copy_area(const GdkPixbuf *src_pixbuf, int src_x, int src_y,
+                          int width, int height, GdkPixbuf *dest_pixbuf,
+                          int dest_x, int dest_y) {
+  /* XXX do nothing */
+}
+
+GdkPixbuf *gdk_pixbuf_scale_simple(const GdkPixbuf *src, int dest_width, int dest_height,
+                                   GdkInterpType interp_type) {
+  GdkPixbuf *dst = gdk_pixbuf_new(GDK_COLORSPACE_RGB, src->has_alpha, 8, dest_width, dest_height);
+
+  if (dst) {
+    guchar *dst_data = dst->data;
+    guchar *src_data = src->data;
+
+#if 0
+    int y;
+    int height = BL_MIN(src->height, dst->height);
+    int stride = BL_MIN(src->stride, dst->stride);
+
+    for (y = 0; y < height; y++) {
+      memcpy(dst_data, src_data, stride);
+      dst_data += dst->stride;
+      src_data += src->stride;
+    }
+#else
+    stbir_resize_uint8_srgb(src_data, src->width, src->height, src->stride,
+                            dst_data, dst->width, dst->height, dst->stride,
+                            STBIR_RGBA);
+#endif
+  }
+
+  return dst;
+}
+
+
+#define gdk_pixbuf_get_width(pixbuf) (pixbuf)->width
+#define gdk_pixbuf_get_height(pixbuf) (pixbuf)->height
+#define gdk_pixbuf_get_rowstride(pixbuf) (pixbuf)->stride
+#define gdk_pixbuf_get_has_alpha(pixbuf) (pixbuf)->has_alpha
+#define gdk_pixbuf_get_pixels(pixbuf) (pixbuf)->data
+
+
+#include "gdk-pixbuf.c"
