$NetBSD: patch-gfx_ycbcr_yuv__row__arm.S,v 1.1 2015/04/28 12:06:34 joerg Exp $

--- gfx/ycbcr/yuv_row_arm.S.orig	2015-04-25 13:25:04.000000000 +0000
+++ gfx/ycbcr/yuv_row_arm.S
@@ -74,7 +74,10 @@ YCbCr42xToRGB565_DITHER30_CONSTS_NEON:
     .global ScaleYCbCr42xToRGB565_BilinearY_Row_NEON
     .type   ScaleYCbCr42xToRGB565_BilinearY_Row_NEON, %function
     .balign 64
+#if defined(__ARM_EABI__) && !defined(__ARM_DWARF_EH__)
     .fnstart
+#endif
+    .cfi_startproc
 ScaleYCbCr42xToRGB565_BilinearY_Row_NEON:
     STMFD       r13!,{r4-r9,r14}       @ 8 words.
     ADR         r14,YCbCr42xToRGB565_DITHER03_CONSTS_NEON
@@ -296,7 +299,10 @@ s42xbily_neon_tail:
 s42xbily_neon_done:
     VPOP        {Q4-Q7}                @ 16 words.
     LDMFD       r13!,{r4-r9,PC}        @ 8 words.
+#if defined(__ARM_EABI__) && !defined(__ARM_DWARF_EH__)
     .fnend
+#endif
+    .cfi_endproc
     .size ScaleYCbCr42xToRGB565_BilinearY_Row_NEON, .-ScaleYCbCr42xToRGB565_BilinearY_Row_NEON
 
 #if defined(__ELF__)&&defined(__linux__)
