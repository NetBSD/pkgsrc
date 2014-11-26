$NetBSD: patch-gfx_ycbcr_yuv__row__arm.s,v 1.1 2014/11/26 14:56:28 ryoon Exp $

--- gfx/ycbcr/yuv_row_arm.s.orig	2014-11-13 22:49:57.000000000 +0000
+++ gfx/ycbcr/yuv_row_arm.s
@@ -299,6 +299,6 @@ s42xbily_neon_done:
     .fnend
     .size ScaleYCbCr42xToRGB565_BilinearY_Row_NEON, .-ScaleYCbCr42xToRGB565_BilinearY_Row_NEON
 
-#if defined(__ELF__)&&defined(__linux__)
+#if defined(__ELF__)&&(defined(__linux__) || defined(__NetBSD__))
     .section .note.GNU-stack,"",%progbits
 #endif
