$NetBSD: patch-jpg.c,v 1.1 2023/05/23 22:31:46 nikita Exp $

Build with both jpeg and libjpeg-turbo.

--- jpg.c.orig	2020-08-05 04:57:41.000000000 +0000
+++ jpg.c
@@ -67,7 +67,11 @@ void* read_JPEG_file(char *file_path, JP
 
     // BGRA + endianness change = RGBA?
     // TODO: Test this code on non-x86_64 platforms
+#ifdef JCS_EXTENSIONS
     cinfo.out_color_space = JCS_EXT_BGRA;
+#else
+    cinfo.out_color_space = JCS_RGB;
+#endif
 
     (void) jpeg_start_decompress(&cinfo);
 
