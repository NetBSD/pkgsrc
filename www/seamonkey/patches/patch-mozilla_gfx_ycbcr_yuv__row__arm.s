$NetBSD: patch-mozilla_gfx_ycbcr_yuv__row__arm.s,v 1.1 2015/12/03 12:22:27 ryoon Exp $

--- mozilla/gfx/ycbcr/yuv_row_arm.s.orig	2015-11-04 01:55:29.000000000 +0000
+++ mozilla/gfx/ycbcr/yuv_row_arm.s
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
@@ -296,7 +303,8 @@ s42xbily_neon_tail:
 s42xbily_neon_done:
     VPOP        {Q4-Q7}                @ 16 words.
     LDMFD       r13!,{r4-r9,PC}        @ 8 words.
-    .fnend
+    UNWIND .fnend
+    .cfi_endproc
     .size ScaleYCbCr42xToRGB565_BilinearY_Row_NEON, .-ScaleYCbCr42xToRGB565_BilinearY_Row_NEON
 
 #if defined(__ELF__)&&defined(__linux__)
