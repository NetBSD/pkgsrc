$NetBSD: patch-wrlib_gif.c,v 1.2 2014/05/16 09:29:39 tron Exp $

Fix build with giflib 5.1 and newer.

--- wrlib/gif.c.orig	2013-09-12 22:43:54.000000000 +0100
+++ wrlib/gif.c	2014-05-16 10:10:04.000000000 +0100
@@ -52,6 +52,7 @@
 	unsigned char rmap[256];
 	unsigned char gmap[256];
 	unsigned char bmap[256];
+	int gif_error;
 
 	if (index < 0)
 		index = 0;
@@ -59,10 +60,10 @@
 	/* default error message */
 	RErrorCode = RERR_BADINDEX;
 
-	gif = DGifOpenFileName(file);
+	gif = DGifOpenFileName(file, &gif_error);
 
 	if (!gif) {
-		switch (GifLastError()) {
+		switch (gif_error) {
 		case D_GIF_ERR_OPEN_FAILED:
 			RErrorCode = RERR_OPEN;
 			break;
@@ -77,7 +78,7 @@
 	}
 
 	if (gif->SWidth < 1 || gif->SHeight < 1) {
-		DGifCloseFile(gif);
+		DGifCloseFile(gif, NULL);
 		RErrorCode = RERR_BADIMAGEFILE;
 		return NULL;
 	}
@@ -199,7 +200,7 @@
 	/* yuck! */
 	goto did_not_get_any_errors;
  giferr:
-	switch (GifLastError()) {
+	switch (gif->Error) {
 	case D_GIF_ERR_OPEN_FAILED:
 		RErrorCode = RERR_OPEN;
 		break;
@@ -220,7 +221,7 @@
 		free(buffer);
 
 	if (gif)
-		DGifCloseFile(gif);
+		DGifCloseFile(gif, NULL);
 
 	return image;
 }
