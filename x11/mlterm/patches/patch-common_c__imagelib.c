$NetBSD: patch-common_c__imagelib.c,v 1.1 2014/03/23 07:04:00 tsutsui Exp $

Pull post-3.3.4 bug fixes patch:
http://sourceforge.net/projects/mlterm/files/01release/mlterm-3.3.4/mlterm-3.3.4-fixes.patch/download
 - fix build error on NetBSD and OpenBSD with framebuffer support.

--- common/c_imagelib.c.orig	2014-03-22 22:06:31.000000000 +0000
+++ common/c_imagelib.c
@@ -795,6 +795,9 @@ end:
 	return  pixels ;
 }
 
+
+#ifndef  __CONVERT_REGIS_TO_BMP__
+#define  __CONVERT_REGIS_TO_BMP__
 #ifdef  USE_WIN32API
 
 static int
@@ -905,6 +908,7 @@ convert_regis_to_bmp(
 }
 
 #endif
+#endif	/* CONVERT_REGIS_TO_BMP */
 
 
 #ifndef  SIXEL_1BPP
