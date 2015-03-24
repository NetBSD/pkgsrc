$NetBSD: patch-src_gui_image_qbmphandler.cpp,v 1.1 2015/03/24 21:43:52 bsiegert Exp $
https://codereview.qt-project.org/#/c/107108/4

Fix a division by zero when processing malformed BMP files.
This fixes a division by 0 when processing a maliciously crafted BMP
file. No impact beyond DoS.
--- src/gui/image/qbmphandler.cpp.orig	2015-03-24 20:09:44.000000000 +0000
+++ src/gui/image/qbmphandler.cpp
@@ -319,10 +319,16 @@ static bool read_dib_body(QDataStream &s
         }
     } else if (comp == BMP_BITFIELDS && (nbits == 16 || nbits == 32)) {
         red_shift = calc_shift(red_mask);
+	if (((red_mask >> red_shift) + 1) == 0)
+            return false;
         red_scale = 256 / ((red_mask >> red_shift) + 1);
         green_shift = calc_shift(green_mask);
+	if (((green_mask >> green_shift) + 1) == 0)
+            return false;
         green_scale = 256 / ((green_mask >> green_shift) + 1);
         blue_shift = calc_shift(blue_mask);
+	if (((blue_mask >> blue_shift) + 1) == 0)
+            return false;
         blue_scale = 256 / ((blue_mask >> blue_shift) + 1);
     } else if (comp == BMP_RGB && (nbits == 24 || nbits == 32)) {
         blue_mask = 0x000000ff;
