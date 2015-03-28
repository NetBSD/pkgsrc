$NetBSD: patch-src_gui_image_qbmphandler.cpp,v 1.1 2015/03/28 17:04:50 bsiegert Exp $
https://codereview.qt-project.org/#/c/106929/4

Fix a division by zero when processing malformed BMP files.

This fixes a division by 0 when processing a maliciously crafted BMP
file. No impact beyond DoS.
--- src/gui/image/qbmphandler.cpp.orig	2015-03-24 21:58:44.000000000 +0000
+++ src/gui/image/qbmphandler.cpp
@@ -314,12 +314,20 @@ static bool read_dib_body(QDataStream &s
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
         alpha_shift = calc_shift(alpha_mask);
+	if (((alpha_mask >> alpha_shift) + 1) == 0)
+            return false;
         alpha_scale = 256 / ((alpha_mask >> alpha_shift) + 1);
     } else if (comp == BMP_RGB && (nbits == 24 || nbits == 32)) {
         blue_mask = 0x000000ff;
