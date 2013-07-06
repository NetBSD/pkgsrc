$NetBSD: patch-wrlib_gif.c,v 1.1 2013/07/06 10:19:31 tron Exp $

Fix build with GIFLIB 5.0 and newer.

--- wrlib/gif.c.orig	2013-01-09 21:42:39.000000000 +0000
+++ wrlib/gif.c	2013-07-06 11:13:26.000000000 +0100
@@ -50,6 +50,7 @@
 	unsigned char rmap[256];
 	unsigned char gmap[256];
 	unsigned char bmap[256];
+	int gif_error;
 
 	if (index < 0)
 		index = 0;
@@ -57,10 +58,10 @@
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
@@ -197,7 +198,7 @@
 	/* yuck! */
 	goto did_not_get_any_errors;
  giferr:
-	switch (GifLastError()) {
+	switch (gif->Error) {
 	case D_GIF_ERR_OPEN_FAILED:
 		RErrorCode = RERR_OPEN;
 		break;
