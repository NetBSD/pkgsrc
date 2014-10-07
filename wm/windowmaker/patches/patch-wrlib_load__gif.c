$NetBSD: patch-wrlib_load__gif.c,v 1.1 2014/10/07 16:11:11 adam Exp $

Fix build with giflib 5.1 and newer.

--- wrlib/load_gif.c.orig	2014-10-07 12:55:29.000000000 +0000
+++ wrlib/load_gif.c
@@ -81,7 +81,7 @@ RImage *RLoadGIF(const char *file, int i
 	}
 
 	if (gif->SWidth < 1 || gif->SHeight < 1) {
-		DGifCloseFile(gif);
+		DGifCloseFile(gif, NULL);
 		RErrorCode = RERR_BADIMAGEFILE;
 		return NULL;
 	}
@@ -216,7 +216,7 @@ RImage *RLoadGIF(const char *file, int i
 		free(buffer);
 
 	if (gif)
-		DGifCloseFile(gif);
+		DGifCloseFile(gif, NULL);
 
 	return image;
 }
