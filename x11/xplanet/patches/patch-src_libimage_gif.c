$NetBSD: patch-src_libimage_gif.c,v 1.4 2019/11/16 17:36:28 ng0 Exp $

* Fix build with giflib 5.1.

--- src/libimage/gif.c.orig	2006-03-25 22:50:51.000000000 +0000
+++ src/libimage/gif.c
@@ -21,7 +21,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
-
+#include <stdbool.h>
 #include <gif_lib.h>
 
 /*
@@ -178,8 +178,12 @@ read_gif(const char *filename, int *width, int *height, unsigned char **rgb)
 	    *BufferP++ = ColorMapEntry->Blue;
 	}
     }
-    
+
+#if GIFLIB_MAJOR >= 5
+    if (DGifCloseFile(GifFile, NULL) == GIF_ERROR) {
+#else
     if (DGifCloseFile(GifFile) == GIF_ERROR) {
+#endif
 	return(0);
     }
 
@@ -493,7 +497,11 @@ SortCmpRtn(const void *Entry1,
 static void QuitGifError(GifFileType *GifFile)
 {
     fprintf(stderr, "Error writing GIF file\n");
+#if GIFLIB_MAJOR >= 5
+    if (GifFile != NULL) EGifCloseFile(GifFile, NULL);
+#else
     if (GifFile != NULL) EGifCloseFile(GifFile);
+#endif
 }
 
 int 
@@ -589,7 +597,11 @@ write_gif(const char *filename, int width, int height, char *rgb)
 	Ptr += width;
     }
 
+#if GIFLIB_MAJOR >= 5
+    if (EGifCloseFile(GifFile, NULL) == GIF_ERROR)
+#else
     if (EGifCloseFile(GifFile) == GIF_ERROR)
+#endif
 
     {
 	QuitGifError(GifFile);
