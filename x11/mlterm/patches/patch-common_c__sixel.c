$NetBSD: patch-common_c__sixel.c,v 1.1 2024/09/22 21:40:32 tsutsui Exp $

- pull upstream transparent fixes:
  https://github.com/arakiken/mlterm/commit/51232032
  > * c_sixel.c: load_sixel_from_{data|file}() check whether P2 is 1 or not
  >   and return it by 'transparent' argument.

--- common/c_sixel.c.orig	2023-04-01 13:54:40.000000000 +0000
+++ common/c_sixel.c
@@ -292,7 +292,8 @@ static void correct_height(pixel_t *pixe
  * the actual image size is less than it.
  * It is the caller that should shrink (realloc) it.
  */
-static u_char *load_sixel_from_data(const char *file_data, u_int *width_ret, u_int *height_ret) {
+static u_char *load_sixel_from_data(const char *file_data, u_int *width_ret, u_int *height_ret,
+                                    int *transparent) {
   const char *p = file_data;
   u_char *pixels;
   int params[6];
@@ -375,6 +376,11 @@ static u_char *load_sixel_from_data(cons
   }
 #endif
 
+  /* Place here this in case 'goto end' or 'goto body'. */
+  if (transparent) {
+    *transparent = 0; /* can be changed in processing P2. */
+  }
+
 restart:
   while (1) {
     if (*p == '\0') {
@@ -465,25 +471,34 @@ restart:
     switch (*p) {
     case 'q':
       goto body;
+
 #ifdef SIXEL_ORMODE
     case '5':
       ormode = 1;
       break;
 #endif
-#if 0
-    case '0':
-    case '2':
-      ...
+
+    case '1':
+      if (transparent) {
+        *transparent = 1;
+      }
       break;
 
-    default:
-#else
     case '\0':
-#endif
 #ifdef DEBUG
       bl_debug_printf(BL_DEBUG_TAG " Illegal format.\n.");
 #endif
       goto end;
+
+#if 0
+    case '0':
+    case '2':
+#endif
+    default:
+#ifdef DEBUG
+      bl_debug_printf(BL_DEBUG_TAG " Illegal format.\n.");
+#endif
+      break;
     }
 
     if (p[1] == ';') {
@@ -956,12 +971,13 @@ error:
 
 #if !defined(SIXEL_1BPP) && !defined(SIXEL_SHAREPALETTE)
 
-static u_char *load_sixel_from_file(const char *path, u_int *width_ret, u_int *height_ret) {
+static u_char *load_sixel_from_file(const char *path, u_int *width_ret, u_int *height_ret,
+                                    int *transparent) {
   char *file_data;
   u_char *pixels;
 
   if ((file_data = read_sixel_file(path))) {
-    pixels = load_sixel_from_data(file_data, width_ret, height_ret);
+    pixels = load_sixel_from_data(file_data, width_ret, height_ret, transparent);
     free(file_data);
 
     return pixels;
