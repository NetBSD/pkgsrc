$NetBSD: patch-gfx_skia_skia_src_opts_memset.arm.S,v 1.1 2016/04/27 16:36:50 ryoon Exp $

--- gfx/skia/skia/src/opts/memset.arm.S.orig	2015-10-22 22:30:24.000000000 +0000
+++ gfx/skia/skia/src/opts/memset.arm.S
@@ -13,6 +13,12 @@
  *    to aid future maintenance.
  */
 
+#if defined(__ARM_EABI__) && !defined(__ARM_DWARF_EH__)
+#define UNWIND
+#else
+#define UNWIND @
+#endif
+
     .text
     .align 4
     .syntax unified
@@ -30,7 +36,8 @@
  *
  */
 arm_memset16:
-        .fnstart
+	.cfi_startproc
+        UNWIND .fnstart
         push        {lr}
 
         /* if count is equal to zero then abort */
@@ -51,10 +58,12 @@ arm_memset16:
 
         /* Now jump into the main loop below. */
         b           .Lwork_32
-        .fnend
+        UNWIND .fnend
+	.cfi_endproc
 
 arm_memset32:
-        .fnstart
+	.cfi_startproc
+        UNWIND .fnstart
         push        {lr}
 
         /* if count is equal to zero then abort */
@@ -108,4 +117,5 @@ arm_memset32:
 
 .Lfinish:
         pop         {pc}
-        .fnend
+        UNWIND .fnend
+	.cfi_endproc
