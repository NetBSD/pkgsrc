$NetBSD: patch-gfx_ycbcr_yuv__row__arm.S,v 1.4 2017/06/14 11:28:44 ryoon Exp $

* Copy from yuv_row_arm.s to process it with pre-processor

--- gfx/ycbcr/yuv_row_arm.S.orig	2017-06-12 20:07:14.598490411 +0000
+++ gfx/ycbcr/yuv_row_arm.S
@@ -2,6 +2,12 @@
  * License, v. 2.0. If a copy of the MPL was not distributed with this
  * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
 
+#if defined(__ARM_EABI__) && !defined(__ARM_DWARF_EH__)
+#define UNWIND
+#else
+#define UNWIND @
+#endif
+
     .arch   armv7-a
     .fpu    neon
 /* Allow to build on targets not supporting neon, and force the object file
@@ -74,7 +80,8 @@ YCbCr42xToRGB565_DITHER30_CONSTS_NEON:
     .global ScaleYCbCr42xToRGB565_BilinearY_Row_NEON
     .type   ScaleYCbCr42xToRGB565_BilinearY_Row_NEON, %function
     .balign 64
-    .fnstart
+    .cfi_startproc
+    UNWIND .fnstart
 ScaleYCbCr42xToRGB565_BilinearY_Row_NEON:
     STMFD       r13!,{r4-r9,r14}       @ 8 words.
     ADR         r14,YCbCr42xToRGB565_DITHER03_CONSTS_NEON
@@ -296,9 +303,10 @@ s42xbily_neon_tail:
 s42xbily_neon_done:
     VPOP        {Q4-Q7}                @ 16 words.
     LDMFD       r13!,{r4-r9,PC}        @ 8 words.
-    .fnend
+    UNWIND .fnend
+    .cfi_endproc
     .size ScaleYCbCr42xToRGB565_BilinearY_Row_NEON, .-ScaleYCbCr42xToRGB565_BilinearY_Row_NEON
 
-#if defined(__ELF__)&&defined(__linux__)
+#if defined(__ELF__)&&(defined(__linux__) || defined(__NetBSD__))
     .section .note.GNU-stack,"",%progbits
 #endif
