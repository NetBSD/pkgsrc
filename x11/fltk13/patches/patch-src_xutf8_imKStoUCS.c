$NetBSD: patch-src_xutf8_imKStoUCS.c,v 1.1 2015/07/21 21:36:41 markd Exp $

part of tigervnc.patch from archlinux package. 

--- src/xutf8/imKStoUCS.c.orig	2014-08-21 14:03:52.000000000 +0000
+++ src/xutf8/imKStoUCS.c
@@ -266,6 +266,12 @@ static unsigned short const keysym_to_un
     0x20a8, 0x20a9, 0x20aa, 0x20ab, 0x20ac                          /* 0x20a8-0x20af */
 };
 
+static unsigned short const keysym_to_unicode_fe50_fe60[] = {
+    0x0300, 0x0301, 0x0302, 0x0303, 0x0304, 0x0306, 0x0307, 0x0308, /* 0xfe50-0xfe57 */
+    0x030a, 0x030b, 0x030c, 0x0327, 0x0328, 0x1da5, 0x3099, 0x309a, /* 0xfe58-0xfe5f */
+    0x0323                                                          /* 0xfe60-0xfe67 */
+};
+
 static unsigned int
 KeySymToUcs4(KeySym keysym)
 {
@@ -315,6 +321,8 @@ KeySymToUcs4(KeySym keysym)
 	return keysym_to_unicode_1e9f_1eff[keysym - 0x1e9f];
     else if (keysym > 0x209f && keysym < 0x20ad)
 	return keysym_to_unicode_20a0_20ac[keysym - 0x20a0];
+    else if (keysym > 0xfe4f && keysym < 0xfe61)
+	return keysym_to_unicode_fe50_fe60[keysym - 0xfe50];
     else 
 	return 0;
 }
