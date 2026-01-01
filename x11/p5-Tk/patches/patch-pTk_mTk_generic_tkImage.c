$NetBSD: patch-pTk_mTk_generic_tkImage.c,v 1.1 2026/01/01 09:36:08 mef Exp $

gcd-14.3.9 flags as follows

tkImage.c:1080:1: error: type of 'imgHeight' defaults to 'int' [-Wimplicit-int]
tkImage.c:1086:5: error: declaration for parameter 'imgHeitht' but no such parameter
 1086 | int imgHeitht;
      |     ^~~~~~~~~
*** Error code 1

--- pTk/mTk/generic/tkImage.c 2026-01-01 17:59:04.418755442 +0900
+++ pTk/mTk/generic/tkImage.c 2026-01-01 17:59:04.418755442 +0900
@@ -1083,6 +1083,8 @@ int x;
 int y;
 int width;
 int height;
+int imgHeight;
+int imgWidth;
 {
     Tk_Tile tile = (Tk_Tile) clientData;
     Tk_TileChange *handler;
